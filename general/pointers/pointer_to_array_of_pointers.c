#include <stdio.h>

void
f(char **s)
{
        printf("In function, the address passed to the function:\n%p\n", s);
        printf("In function, value of array's first element:\n%p\n", *s);
}

int
main(int argc, char *argv[])
{
        // An array of character pointers
        char *a[] = {
                "Test", "Test again"
        };

        /* The address of the array's first element;
         * the address of the first pointer of the array */
        printf("In main, the address of the array's first element:\n%p\n", a);

        /* The actual array's first element that contains the address of the
         * "Test" string literal */
        printf("In main, value of array's first element:\n%p\n", *a);

        /* Pass the address of the array's first element,
         * The called function has to dereference the pointer to access
         * the string. */
        f(a);

        return 0;
}
