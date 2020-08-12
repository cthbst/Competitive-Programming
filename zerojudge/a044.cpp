#include <stdio.h>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", 1 + n * (n * n + 5) / 6);
    }
}
