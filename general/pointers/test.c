// Read this if you are confuse about a pointer to pointer
#include <stdio.h>

void
f(int **i)
{
        printf("%p\n", i);
        printf("%p\n", *i);
        *i = *i+1;
        printf("%d\n", **i);
}

int
main()
{
        int arr[] = { 3, 1, 2 };
        int *p = arr;

        printf("&arr[0]\t= %p\n", &arr[0]);
        printf("&arr[1]\t= %p\n", &arr[1]);
        printf("p\t= %p\n", p);
        printf("&p\t= %p\n", &p);

        f(&p);

        printf("%d\n", *p);
        
        return 0;
}
