#include <stdio.h>

#define MAX_INPUT 1000

void shellsort(int v[], int n);

int main(void)
{
        int i = MAX_INPUT;
        int v[MAX_INPUT];
        int j = 0;
        
        while (i > 0)
                v[j++] = i--;

        int len = sizeof(v) / sizeof(v[0]);
        shellsort(v, len);

        for (i = 0; i < MAX_INPUT; i++)
                printf("%d\n", v[i]);

        return 0;
}

/* shellsort:  sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
        int gap, i, j, temp;

        for (gap = n/2; gap > 0; gap /= 2) {
                for (i = gap; i < n; i++) {
                        for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                                temp = v[j];
                                v[j] = v[j+gap];
                                v[j+gap] = temp;
                        }
                }
        }
}
