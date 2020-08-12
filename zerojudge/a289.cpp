#include <stdio.h>

int main() {
    int dp[30][3];
    dp[0][1] = 1;
    dp[0][2] = 0;
    dp[1][1] = 0;
    dp[1][2] = 1;

    while (~scanf("%d%d", &dp[0][0], &dp[1][0])) {
        int t = 2;
        while (1) {
            int d = dp[t - 2][0] / dp[t - 1][0];
            dp[t][0] = dp[t - 2][0] % dp[t - 1][0];
            dp[t][1] = dp[t - 2][1] - d * dp[t - 1][1];
            dp[t][2] = dp[t - 2][2] - d * dp[t - 1][2];
            if (dp[t][0] == 0 || dp[t][0] == 1) break;
            t++;
        }
        if (dp[t][0] == 0)
            puts("No Inverse");
        else {
            printf("%d\n", dp[t][1] >= 0 ? dp[t][1] : dp[t][1] + dp[1][0]);
        }
    }
}
