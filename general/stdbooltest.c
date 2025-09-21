#include <stdio.h>
#include <stdbool.h>

bool check(int x) {
    if (x == 0)
        return 1;
    else
        return 0;
    return 0;
}

int main() {
    char str[] = "Ganbarimasu";
    printf("%s\n",str);
    if (check(0)) {
        printf("%s\n", "x is equal to 0, and return 1 in stdbool library in c means true, opposite to bash convention of 0 = true");
    } else {
        printf("%s\n", "1 is really equals to true in c stdbool library as expected but in int main 0 which expects a return type of int means that the program runs without errors");
    }
    return 0;
}
