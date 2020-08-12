#include <stdio.h>

typedef long long int LL;

int main() {
    LL N, M;
    while (~scanf("%lld%lld", &N, &M)) {
        if (N < 3)
            printf("%lld\n", 1 % M);
        else {
            LL a[3];
            a[0] = a[1] = 1;
            for (LL i = 3; i <= N; i++) {
                a[2] = (a[1] * (i - 1) + a[0] * (i - 2)) % M;
                a[0] = a[1];
                a[1] = a[2];
            }
            printf("%lld\n", a[2]);
        }
    }
}
