#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void
filecopy(FILE *ifp, FILE *ofp)
{
        int c;

        while ((c = getc(ifp)) != EOF)
                putc(c, ofp);
}

int
main(int argc, char **argv)
{
        FILE* fp;
        char *prog = *argv;

        if (argc == 1)
                filecopy(stdin, stdout);
        else {
                while (--argc) {
                        if ((fp = fopen(*++argv, "r")) == NULL) {
                                fprintf(stderr, "%s: ", prog);
                                perror(*argv);
                                exit(1);
                        } else {
                                filecopy(fp, stdout);
                                fclose(fp);
                        }
                }

                if (ferror(stdout)) {
                        fprintf(stderr, "%s: error writing stdout\n", prog);
                        exit(2);
                }
                exit(0);
        }
}
