#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* get_line: get line into s, return length */
int
_getline(char *s, int max)
{
        int c;
        char *p = s;

        while (--max > 0 && (c = getchar()) != EOF && c != '\n')
                *s++ = c;

        if (c == '\n')
                *s++ = c;

        *s = '\0';
        return s - p;
}

/* find: print lines that match pattern from 1st arg */
int
main(int argc, char *argv[])
{
        char line[MAXLINE];
        long lineno;
        int c;
        int except;
        int number;
        int found;

        lineno = 0;
        except = 0;
        number = 0;
        found = 0;

        while (--argc > 0 && (*++argv)[0] == '-') {
                /* printf("%p %c\n", argv[0], *argv[0]); */
                /* printf("%p\n", ++(argv[0])); */
                while ((c = *++argv[0])) {
                        switch (c) {
                        case 'x':
                                except = 1;
                                break;
                        case 'n':
                                number = 1;
                                break;
                        default:
                                printf("find: illegal option %c\n", c);
                                argc = 0;
                                found = -1;
                                break;
                        }
                }
        }

        if (argc != 1)
                printf("Usage: find -x -n pattern\n");
        else {
                while (_getline(line, MAXLINE) > 0) {
                        lineno++;
                        if ((strstr(line, *argv) != NULL) != except) {
                                if (number)
                                        printf("%ld:", lineno);
                                printf("%s", line);
                                found++;
                        }
                }
        }

        return found;
}
