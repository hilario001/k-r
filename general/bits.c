#include <stdio.h>
#include <stdlib.h>

void
print_bits(int i, size_t size)
{
        if (size) {
                print_bits(i >> 1, --size);
                printf("%d", i & 0x01);
        }
}

int
main(int argc, char *argv[])
{
        while (--argc) {
                print_bits(atoi(*++argv), sizeof(int) * 8);
                printf("\n");
        }

        return 0;
}
