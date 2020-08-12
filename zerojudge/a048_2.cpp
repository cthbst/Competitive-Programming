#include <stdio.h>
#include <string.h>

int N, Q;
int bit[500000];

void add(int x) {
    while (x <= N) {
        bit[x]++;
        x += x & (-x);
    }
}

int sum(int x) {
    int re = 0;
    while (x > 0) {
        re += bit[x];
        x = x & (x - 1);
    }
    return re;
}

int main() {
    while (~scanf("%d%d", &N, &Q)) {
        memset(bit, 0, sizeof(bit));
        int type, a, b;
        while (Q-- && scanf("%d", &type)) {
            if (type == 1 && scanf("%d", &a)) {
                add(a);
            } else {
                scanf("%d%d", &a, &b);
                printf("%d\n", ((sum(b) - sum(a - 1)) & 1) == 1 ? 1 : 0);
            }
        }
    }
}
