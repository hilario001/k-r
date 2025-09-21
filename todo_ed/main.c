/* Line-oriented to-do app              */
/* Commands                             */
/* p       -       print to-dos         */
/* d       -       print done to-dos    */
/* a       -       add a todo           */
/* r       -       remove a todo        */
/* m       -       mark as done a todo  */
/* h       -       print this help      */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_FILE todo

void add(char *s);
void print(const char *c);
void rm(void);
void mark(void);
void clear_all(void);

int
main(int argc, char **argv)
{
        char c[100];            /* Use for command input */
        char s[1000];           /* Store to do line input */

        while (fgets(c, sizeof(c), stdin) != NULL) {
                switch (*c) {   /* Parse the first character */
                case 'p':
                        print("todo");
                        break;
                case 'd':
                        print("done");
                        break;
                case 'a':
                        fgets(s, sizeof(s), stdin);
                        add(s);
                        break;
                case 'q':
                        return 0;
                default:
                        printf("%c\n", '?');
                        break;
                }
        }
        return 0;
}

void
add(char *s)
{
        FILE *f = fopen(TODO_FILE, "a");
        char *p = s;

        if (f == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
        }

        s += strlen(s) - 1;
        *s++ = '|';
        *s++ = 't';
        *s++ = '\n';
        *s = '\0';
        fprintf(f, p);
        
        fclose(f);
}

void
print(const char *c)
{
        FILE *f = fopen(TODO_FILE, "r");
        char line[1000];
        char *p, *s, *tmp;

        if (f == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
        }

        while ((s = fgets(line, sizeof(line), f)) != NULL) {
                p = s;
                tmp = s;

                /* Since line is saved with suffix of '|t' for a */
                /* todo line and '|d' for a done line, decrement s */
                /* to point in that location. */
                s += strlen(s) - 2;

                /* Truncate the line until '|' for printing. */
                while (*p != '|')
                        ++p;

                if (*s == *c) {
                        *p++ = '\n';
                        *p = '\0';
                        printf("%s", tmp);
                }
        }

        fclose(f);
}

void
mark(void)
{

}
