#include <stdio.h>

typedef long long int LL;

int main() {
    LL n, m;
    while (~scanf("%lld%lld", &n, &m)) {
        LL ans = 1;
        for (int i = n; i > m; i--) {
            ans *= i;
        }
        for (int i = 2; i <= (n - m); i++) {
            ans /= i;
        }
        printf("%lld\n", ans);
    }
}
