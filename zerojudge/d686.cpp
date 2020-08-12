#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;

int dp[60][60];
int s[60];

int dps(int i, int j) {
    if (dp[i][j] >= 0) return dp[i][j];
    if (i == j) return dp[i][j] = 0;

    dp[i][j] = 1 << 29;
    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dps(i, k) + dps(k + 1, j));
    }
    return dp[i][j] = dp[i][j] + s[j] - s[i - 1];
}

int main() {
    int L, N;
    while (scanf("%d", &L) && L != 0) {
        // input -------------
        scanf("%d", &N);
        s[0] = 0;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &s[i]);
        }
        s[N + 1] = L;
        // dp ----------------
        memset(dp, -1, sizeof(dp));

        // output ------------
        printf("The minimum cutting is %d.\n", dps(1, N + 1));
    }
}
