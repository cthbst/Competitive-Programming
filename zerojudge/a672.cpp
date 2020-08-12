#include <stdio.h>

int K, X, Y, ans;

void walk(int x, int y, int k) {
    if (k == 0) return;
    int l = x - k, r = x + k, d = y - k, t = y + k;
    if (l <= X && X <= r && d <= Y && Y <= t) ans++;
    if (X >= x && Y >= y) walk(r, t, k / 2);
    if (X <= x && Y >= y) walk(l, t, k / 2);
    if (X >= x && Y <= y) walk(r, d, k / 2);
    if (X <= x && Y <= y) walk(l, d, k / 2);
}

int main() {
    while (~scanf("%d%d%d", &K, &X, &Y) && !(!K && !X && !Y)) {
        ans = 0;
        walk(1024, 1024, K);
        printf("%d\n", ans);
    }
}
