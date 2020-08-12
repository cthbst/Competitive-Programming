#include <stdio.h>
#include <string.h>

typedef long long int LL;
const LL INF = 1000000000;
int main() {
    LL a[100];
    a[0] = a[1] = 1;
    for (int i = 2; a[i - 1] + a[i - 2] < INF; i++) a[i] = a[i - 1] + a[i - 2];
    LL K;
    while (~scanf("%lld", &K)) {
        int L = 0, R = 43;
        while (L != R) {
            int m = (L + R) / 2;
            if (K < a[m])
                R = m;
            else
                L = m + 1;
        }
        printf("%lld %lld\n", a[L - 2], a[L - 1]);
    }
}
