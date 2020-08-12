#include <stdio.h>

typedef long long int LL;
const LL MOD = 10007;

LL Pow(LL a, LL n) {
    LL re = 1;
    while (n) {
        if (n & 1) re = re * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return re;
}
LL Inverse(LL a) {
    return Pow(a % MOD, MOD - 2);
}

int main() {
    int T;
    scanf("%d", &T);
    LL a, b, q;
    while (T-- && scanf("%lld%lld%lld", &a, &b, &q)) {
        if (q % MOD == q * a % MOD * Inverse(b) % MOD)
            puts("SAFE");
        else
            puts("BOOM");
    }
}
