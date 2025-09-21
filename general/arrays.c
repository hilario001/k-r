#include <stdio.h>

// counts whitespaces, digits, and other characters frequencies
int main()
{
    int c, i;
    int nwhite = 0;
    int nother = 0;
    int ndigit[10];

    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;

    printf("%s", "Digits:");

    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    
    printf("\nWhitespaces: %d\nOther: %d\n", nwhite, nother);

    return 0;
}
