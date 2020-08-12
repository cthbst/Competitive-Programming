#include <stdio.h>

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c)) {
        if (a == 0 && b == 0 && c == 0) break;
        printf("%s\n", c % GCD(b, a % b) == 0 ? "Yes" : "No");
    }
}
