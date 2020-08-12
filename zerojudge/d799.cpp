#include <stdio.h>
#include <string.h>

#define MAXN 500010
typedef long long int LL;
LL bit[2][MAXN];
int N, Q;

void add(LL *t, int n, LL v) {
    while (n <= N) {
        t[n] += v;
        n += n & (-n);
    }
}

LL sum(LL *t, int n) {
    LL re = 0;
    while (n > 0) {
        re += t[n];
        n = n & (n - 1);
    }
    return re;
}

int main() {
    memset(bit, 0, sizeof(bit));
    scanf("%d", &N);
    LL in;

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &in);
        add(bit[0], i, in * (1 - i));
        add(bit[0], 1 + i, in * i);
        add(bit[1], i, in);
        add(bit[1], 1 + i, -in);
    }

    scanf("%d", &Q);
    int type, L, R, V;
    while (Q-- && scanf("%d%d%d", &type, &L, &R)) {
        if (type == 2)
            printf("%lld\n", sum(bit[1], R) * R + sum(bit[0], R) -
                                 sum(bit[1], L - 1) * (L - 1) -
                                 sum(bit[0], L - 1));
        else {
            scanf("%lld", &in);
            add(bit[0], L, in * (1 - L));
            add(bit[0], 1 + R, in * R);
            add(bit[1], L, in);
            add(bit[1], 1 + R, -in);
        }
    }
}
