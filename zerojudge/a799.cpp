#include <stdio.h>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n < 0) n = -n;
        printf("%d\n", n);
    }
}
