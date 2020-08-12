#include <stdio.h>

typedef long long int ll;

int main() {
    ll T, M, N;
    scanf("%lld", &T);
    while (T-- && scanf("%lld%lld", &M, &N)) {
        ll k = (ll)(N / M);
        printf("%lld\n",
               N * (N + 1) / 2 + M * k * (k - 1) / 2 + (N - M * k) * k);
    }
}
