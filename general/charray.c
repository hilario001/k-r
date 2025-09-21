// program: print the longest input line
#include <stdio.h>

#define MAXLINE 1000 // maximum input line length

// getline as an identifier gets in conflict with getline in std lib
// which wasn't a standard function in ansi c
int getlineAnsi(char cline[], int mline); // current line, max line
void copy(char to[], char from[]); 

int main()
{
    int len; // current line length
    int max; // max length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; // longest line saved here

    max = 0;
    while ((len = getlineAnsi(line, MAXLINE)) > 0) // as long as there is a line
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0) // if there was a line
        printf("Length: %d\n%s\n", max - 1, longest); // max - 1: print the accurate length of lines, by removing the newline
    return 0;
}

// getlineAnsi: store the line into cline and return the length
int getlineAnsi(char cline[], int mline)
{
    int c, i;

    // mline - 1 because of how indexing works in array
    for (i = 0; i < mline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        cline[i] = c;

    if (c == '\n')
    {
        cline[i] = c;
        // a line with just '\n' has a length of 1
        // also to increment to account for the null character below
        ++i;
    }

    cline[i] = '\0'; // '\0' mark the end of the string of characters
    return i;
}

// copy: copy value of second array to the first array
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
