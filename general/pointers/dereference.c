/* Created for to understand concepts introduced to gwu os memory exercise */
#include <stdio.h>

int
f(void)
{
        return 0;
}

int
main(int argc, char *argv[])
{
        if (argc == 1)
                printf("%s\n", argv[0]);

        int i = 0;
        int *p = &i;

        printf("%d\n", *p);
        printf("%ld\n", sizeof(int));
}
