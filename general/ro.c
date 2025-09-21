#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
/* #include <sys/syscall.h> */

/* #undef getchar */

void
pc(int c)
{
        write(1, &c, 1);
}

int
g(void)
{
        char c;

        return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int
main()
{
        pc(g());
        char buf[BUFSIZ];
        int n;

        while ((n = read(0, buf, BUFSIZ))) {
                write(1, buf, n);
        }
        write(1, "test\n", 5);

        return 0;
}
