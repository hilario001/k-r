#include <stdio.h>

#define MAXLINE 1000 // max input line length

// checks if the null is included in a character array length
int main()
{
    int c, i, j;
    int line[MAXLINE];

    j = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    printf("Last value of i, where newline will be stored: %d\n", i);
    if (c == '\n') {
        line[i] = c;
        ++i; // to account for null below
    }
    line[i] = '\0'; // mark the end of string
    printf("Value of i after storing null: %d\n", i);

    printf("Length of line including the newline and null: %d\n", i);
    printf("The first index of the line: %c\n", line[0]);
    printf("The character after the null: ");
    line[i + 1] = 'a';
    printf("%c", line[i + 1]);
    printf("\n");
    //printf("%c\n", line[i + 1]);

    return 0;
}
