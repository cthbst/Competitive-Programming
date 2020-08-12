#include <stdio.h>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        long long int dp[n + 2][n + 2];
        for (int i = 0; i <= n; i++) dp[0][i] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][1];
            for (int j = 1; j <= n - i; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
            }
        }

        printf("%lld\n", dp[n][0]);
    }
}
