#include <stdio.h>

typedef long long int LL;
LL T, N, M;
#define max 1000010
LL a[max];

LL check(LL n) {
    LL count = 0;
    LL sum = 0, l = 0, r = 0, lr = 0;
    for (r = 0; r <= N; r++) {
        sum += a[r];
        if (sum > n) {
            count += (r - l) * (r - l + 1) / 2 - (lr - l) * (lr - l + 1) / 2;
            lr = r;
            while (sum > n) sum -= a[l++];
        }
    }
    return count;
}

LL BSA(LL l, LL r) {
    if (l == r) return l;
    LL m = (l + r) / 2;
    if (check(m) < M)
        return BSA(m + 1, r);
    else
        return BSA(l, m);
}

int main() {
    scanf("%lld", &T);
    while (T-- && scanf("%lld%lld", &N, &M)) {
        for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
        a[N] = N * 10010;

        printf("%lld\n", BSA(0, N * 10001) % 1000000007);
    }
}
