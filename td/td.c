#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define PATH "/home/ced/tmp/todo.txt"
#define PATH_HELP "/home/ced/tmp/tdhelp.txt"
#define TODO "T"
#define DONE "D"
#define TODO_ANSIFG "\033[90;22m"
#define DONE_ANSIFG "\033[32;22m"

void
td_clear(void)
{
        open(PATH, O_TRUNC);
}

/* Print all todo/done lines and prefix a number per line.
 * Each number is used as an index of offset[] that
 * stores the offset of the associated line in fp.
 * Do fseek using stored offset and then toggle the state. */
void
td_toggle_type(FILE *fp, char *totype, char *fromtype)
{
        char buf[1024];
        long offset[100];
        long tmp;
        int i, j, n;

        fseek(fp, 0, 0);
        i = 0;
        n = 1;
        while ((tmp = ftell(fp)) >= 0 && fgets(buf, 1024, fp) != NULL) {
                if (*buf == *fromtype) {
                        offset[i++] = tmp;
                        printf("[%d] %s", n++, buf+1);
                }
        }

        if (i) {
                scanf("%d", &j);
                fseek(fp, offset[j-1], 0);
                fwrite(totype, 1, sizeof(char), fp);
        }
}

void
td_toggle_type_ptrn(FILE *fp, char *totype, char *fromtype, char *ptrn)
{
        char buf[1024];
        long offset, tmp;

        fseek(fp, 0, 0);
        offset = 0;
        while ((tmp = ftell(fp)) >= 0 && fgets(buf, 1024, fp) != NULL) {
                if (*buf == *fromtype) {
                        if (strstr(buf, ptrn)) {
                                offset = tmp;
                                break;
                        }
                }
        }

        if (offset == tmp) {
                fseek(fp, offset, 0);
                fwrite(totype, 1, sizeof(char), fp);
        }
}

void
td_print(FILE *fp, char *type)
{
        char buf[1024];

        fseek(fp, 0, 0);
        while (fgets(buf, 1024, fp) != NULL) {
                if (*buf == *type)
                        printf("%s", buf+1);
        }
}
void
td_colorprint(FILE *fp)
{
        char buf[1024];

        fseek(fp, 0, 0);
        while (fgets(buf, 1024, fp) != NULL) {
                if (*buf == *TODO)
                        printf("%s%s\033[0m", TODO_ANSIFG, buf+1);
                else
                        printf("%s%s\033[0m", DONE_ANSIFG, buf+1);
        }
}

void
td_add(FILE *fp, char *buf)
{
        fseek(fp, 0, 2);
        fwrite(TODO, 1, sizeof(char), fp);
        fwrite(buf, strlen(buf), sizeof(char), fp);
}

void
input_handle(FILE *fp, char ch)
{
        char buf[1024];

        switch (ch) {
        case 'p':
                td_print(fp, TODO);
                break;
        case 'P':
                td_print(fp, DONE);
                break;
        case 'c':
                td_colorprint(fp);
                break;
        case 'a':
                while (fgets(buf, 1024, stdin) != NULL)
                        td_add(fp, buf);
                break;
        case 's':
                if (fgets(buf, 1024, stdin))
                        td_toggle_type_ptrn(fp, DONE, TODO, buf);
                break;
        case 'S':
                if (fgets(buf, 1024, stdin))
                        td_toggle_type_ptrn(fp, TODO, DONE, buf);
                break;
        case 'd':
                td_toggle_type(fp, DONE, TODO);
                break;
        case 't':
                td_toggle_type(fp, TODO, DONE);
                break;
        case 'h':
                strcpy(buf, "cat ");
                strcat(buf, PATH_HELP);
                system(buf);
                break;
        case 'r':
                /* printf("\e[1J\e[H"); */
                printf("\033[1J\033[H");
                break;
        case '0':
                td_clear();
                break;
        case 'q':
                exit(0);
                break;
        default:
                fprintf(stderr, "?\n");
                break;
        }
}

int
main(int argc, char **argv)
{
        char *prog = *argv;
        FILE *fp;
        char ch;

        if ((fp = fopen(PATH, "r+")) == NULL) {
                fprintf(stderr, "%s: ", prog);
                perror(PATH);
                exit(1);
        }

        if (argc == 2)
                input_handle(fp, **++argv);
        else {
                while (scanf("%1s", &ch) != EOF)
                        input_handle(fp, ch);
        }

        exit(0);
}
