#include <stdio.h>

void
swap_first_two_chars(char *s)
{
        char tmp;
        tmp = *s;
        *s = *(s+1);
        *(s+1) = tmp;
}

void
print_char_before(char *s)
{
        /* printf("%c\n", *(s-1)); */
        printf("%c\n", *(s-1));
}

int
main()
{
        char s[] = "iFx me";
        printf("%s\n", s);

        swap_first_two_chars(s);
        printf("%s\n", s);              // Fix me
        print_char_before(&s[1]);       // F

        return 0;
}
