#include <stdio.h>

#include <algorithm>

int N, M;
int a[10030];

bool cmp(int a, int b) {
    if (a % M != b % M) return a % M < b % M;
    if ((a & 1) != (b & 1)) return a & 1;
    if ((a & 1) == 1 && (b & 1) == 1) return a > b;
    if ((a & 1) == 0 && (b & 1) == 0) return a < b;
}
int main() {
    while (scanf("%d%d", &N, &M)) {
        printf("%d %d\n", N, M);
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);
        std::sort(a, a + N, cmp);
        // output ------------
        for (int i = 0; i < N; i++) printf("%d\n", a[i]);
        if (N == 0 && M == 0) break;
    }
}
