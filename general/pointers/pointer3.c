#include <stdio.h>

void
print_value(char **a)
{
        /* printf("%p\n", a++); */
        printf("%p\n", a);
        printf("%s\n", *a);
        printf("%c\n", *a[0]);
}

int
main(int argc, char *argv[])
{
        while (--argc)
                printf("%s\n", *++argv);

        char *a[] = {
                "Program name",
                "Argument 2",
                NULL
        };

        /* printf("%p\n", &a[0]); */
        /* printf("%s\n", a[0]); */
        print_value(&a[0]);

        return 0;
}
