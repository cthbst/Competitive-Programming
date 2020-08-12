#include <stdio.h>

int main() {
    unsigned long long int n, m, a, b;

    while (~scanf("%llu%llu", &n, &m)) {
        a = n + 1;
        b = m + 1;
        if (n % 2 == 0) n /= 2;
        if (m % 2 == 0) m /= 2;
        if (a % 2 == 0) a /= 2;
        if (b % 2 == 0) b /= 2;
        printf("%llu\n", n * a * m * b);
    }
}
