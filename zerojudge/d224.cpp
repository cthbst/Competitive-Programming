#include <stdio.h>

int main() {
    long long int n;
    while (~scanf("%lld", &n)) {
        n /= 2;
        printf("%lld\n", (n + 1) * (n + 2) / 2);
    }
}
