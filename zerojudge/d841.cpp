#include <stdio.h>
#include <string.h>

typedef long long int LL;

const int maxN = 100;
LL dp[maxN][maxN];
int from[maxN][maxN];
LL d[maxN];

void output(int l, int r) {
    if (l == r) {
        printf("%d ", l);
        return;
    }
    int m = from[l][r];
    printf("%d ", m);
    if (l < m) output(l, m - 1);
    if (m < r) output(m + 1, r);
}

int main() {
    // input -----------------
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &d[i]);
    }

    // dp --------------------
    memset(dp, 0, sizeof(dp));
    memset(from, -1, sizeof(from));

    for (int l = n; l >= 1; l--) {
        dp[l][l] = d[l];
        for (int r = l + 1; r <= n; r++) {
            dp[l][r] = d[l];
            from[l][r] = l;
            for (int k = r; k >= l; k--) {
                int score = d[k] + dp[l][k - 1] * dp[k + 1][r];
                if (l == k) score = d[k] + dp[k + 1][r];
                if (k == r) score = d[k] + dp[l][k - 1];

                if (score >= dp[l][r]) {
                    dp[l][r] = score;
                    from[l][r] = k;
                }
            }
        }
    }
    // output ----------------
    printf("%lld\n", dp[1][n]);
    output(1, n);
}
