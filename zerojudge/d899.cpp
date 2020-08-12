#include <stdio.h>

int a[10030];

int main() {
    a[0] = 0;
    for (int i = 1; i <= 10000; i++) {
        a[i] = a[i - 1];
        int d = i;
        while (d) {
            if (d % 10 == 2) a[i]++;
            d /= 10;
        }
    }

    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", a[r] - a[l - 1]);
}
