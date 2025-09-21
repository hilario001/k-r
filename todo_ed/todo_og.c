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

void todo_add(char *s);
void todo_print(void);
void todo_print_done(void);

int
main(int argc, char **argv)
{
        char c[100];            /* Use for command input */
        char s[1000];           /* Store to do line input */

        while (fgets(c, sizeof(c), stdin) != NULL) {
                switch (*c) {   /* Parse the first character */
                case 'p':
                        todo_print();
                        break;
                case 'd':
                        todo_print_done();
                        break;
                case 'a':
                        fgets(s, sizeof(s), stdin);
                        todo_add(s);
                        break;
                default:
                        printf("%c\n", '?');
                        break;
                }
        }
}

void
todo_add(char *s)
{
        FILE *f = fopen("todo", "a");

        if (f == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
        }

        fprintf(f, s);
        
        fclose(f);
}

/* Return 1 if a todo line, otherwise 0 */
int
a_todo_line(char *s)
{
        char ptrn[] = "DONE:";
        char *p = ptrn;

        while (*p != ':' && *s++ == *p++)
                ;

        if (*p == ':')
                return 0;
        else
                return 1;
}

void
todo_print(void)
{
        FILE *f = fopen("todo", "r");
        char s[1000];

        if (f == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
        }

        while (fgets(s, sizeof(s), f) != NULL) {
                if (a_todo_line(s))
                        printf("%s", s);
        }

        fclose(f);
}

void
todo_print_done(void)
{
        FILE *f = fopen("todo", "r");
        char s[1000];

        if (f == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
        }

        while (fgets(s, sizeof(s), f) != NULL) {
                if (!a_todo_line(s))
                        printf("%s", s);
        }

        fclose(f);
}
