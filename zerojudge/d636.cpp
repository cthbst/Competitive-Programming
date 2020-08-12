#include <stdio.h>

#define M 10007

int main() {
    long long int a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        long long int ans = 1;
        while (b) {
            if (b % 2) {
                ans = (ans * a) % M;
            }
            a = (a * a) % M;
            b /= 2;
        }
        printf("%lld\n", ans);
    }
}
