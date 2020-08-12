#include <math.h>
#include <stdio.h>

int is_prime(int p) {
    if (p == 1) return 1;
    int k = floor(sqrt(p) + 0.5);

    for (int i = 2; i <= k; i++) {
        if (p % i == 0) return 1;
    }
    return 0;
}

int main() {
    int p;
    while (scanf("%d", &p) && p != 0) {
        printf("%d\n", is_prime(p));
    }
}
