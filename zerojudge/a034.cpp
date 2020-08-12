#include <stdio.h>

void output(int n) {
    if (n > 1) output(n / 2);
    printf("%d", n & 1);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        output(n);
        printf("\n");
    }
}
