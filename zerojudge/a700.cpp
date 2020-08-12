#include <stdio.h>

long long int D[64];

int main() {
    // init ------------------
    D[0] = 1;
    for (int i = 1; i < 64; i++) {
        D[i] = D[i - 1] * 2;
    }

    // solve -----------------
    int x, y;
    while (~scanf("%d%d", &x, &y)) {
        printf("%lld\n", D[8 * x + y - 9]);
    }
}
