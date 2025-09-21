#include <stdio.h>

void
swap(int v[], int i, int j)
{
        int tmp;
        tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
}

void
qsort(int v[], int left, int right)
{
        int i, last;

        if (left >= right)
                return;

        swap(v, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++) {
                if (v[i] < v[left]) {
                        /* printf("%d %d\n", ++last, i); */
                        swap(v, ++last, i);
                }
        }
        printf("%d\n", last);

        swap(v, left, last);
        qsort(v, left, last-1);
        qsort(v, last+1, right);
}

int main()
{
        int a[] = {7, 2, 8, 1, 3, 3};
        int len, i;

        len = sizeof(a) / sizeof(a[0]) - 1;
        qsort(a, 0, len);

        for (i = 0; i < len + 1; ++i)
                printf("%d", a[i]);

        return 0;
}
