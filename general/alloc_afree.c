#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *
alloc(int n) /* return pointer to n characters */
{
        /* printf("%p\n", allocbuf); */
        /* printf("%p\n", allocp); same output as above */
        /* printf("%p\n", allocbuf+ALLOCSIZE); address arithmetic */
        /* printf("%ld\n", &allocbuf[ALLOCSIZE]-allocp); same as below */
        printf("%p\n", allocp);
        if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
                allocp += n;
                return allocp - n; /* old p */
        } else /* not enough room */
                return 0;
}

int
afree(char *p) /* free storage pointed to by p */
{
        if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
                allocp = p;
                return 1;
        }
        return 0;
}

int
main()
{
        char *string1;
        char *string2;
        int i;

        string1 = alloc(5);
        string2 = alloc(5);

        *string1        = 'H';
        *(string1+1)    = 'e';
        *(string1+2)    = 'l';
        *(string1+3)    = 'l';
        *(string1+4)    = 'o';

        *string2        = 'H';
        *(string2+1)    = 'e';
        *(string2+2)    = 'l';
        *(string2+3)    = 'l';
        *(string2+4)    = 'o';

        /* for (i = 0; i < 5; ++i) */
        /*         printf("%c", *(string2+i)); */

        printf("%p %p\n", string1+4, string2);
        printf("%c %c\n", *(string1+4), *string2);

        if (afree(string1))
                printf("No rules that preventing freeing the allocated memory in a way opposite to LIFO\n");

        string1 = alloc(3);

        *string1        = 'H';
        *(string1+1)    = 'i';
        *(string1+2)    = '!';

        for (i = 0; i < 5; ++i)
                printf("%c", *(string1+i));


        return 0;
}
