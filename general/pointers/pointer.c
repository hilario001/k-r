#include <stdio.h>

void
swap(int *px, int *py)
{
        int tmp;

        tmp = *px;
        *px = *py;
        *py = tmp;
}

int
main()
{
        /* Pointer variable */
        int i;
        int *ip = &i; /* pointer ip now points to the address of i */
        printf("%p\n%p\n", ip, &i); /* outputs the same address */

        /* Increment a variable using a pointer that points to it */
        int y = 0;
        int *py = &y;
        ++*py;
        printf("Value of y: %d\n", y); /* 1 */

        /* pp points to whatever py is pointing to */
        int *pp = py;
        ++*pp;
        printf("Value of y: %d\n", y); /* 2 */

        /* Swapping two values by passing their address */
        int a = 97;
        int b = 65;
        printf("Before swaping:\ta: %d, b: %d\n", a, b);
        swap(&a, &b);
        printf("After swaping:\ta: %d, b: %d\n", a, b);

        /* Pointers and arrays */
        int buf[10];
        int *pb = &buf[0];
        printf("%p\n%p\n", pb, buf); /* outputs the same address */

        buf[0] = 2;
        buf[1] = 3;
        printf("%d\n", *++pb); // 3, buf[1]
        printf("%d\n", *--pb); // 2, buf[0]

        return 0;
}
