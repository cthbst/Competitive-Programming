#include <stdio.h>

void output(int a) {
    if (a < 0) {
        printf("-");
        a *= (-1);
    }
    a += 5;
    a /= 10;
    printf("%d", a / 100);
    a %= 100;
    if (a > 0) {
        printf(".");
    }
    if (a != 0) {
        printf("%d", a / 10);
    }
    if (a % 10) {
        printf("%d", a % 10);
    }
    printf("\n");
}

int main() {
    float a1, a2, b1, b2;
    while (~scanf("%f%f%f%f", &a1, &a2, &b1, &b2)) {
        int x = (b2 - b1) / (a1 - a2) * 1000;
        int y = (a1 * b2 - a2 * b1) / (a1 - a2) * 1000;

        output(x);
        output(y);
    }
}
