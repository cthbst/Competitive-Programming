#include <stdio.h>
#include <string.h>

#define M 1000000007
#define MAXK 10030

int mod(int a, int b) {
    int re = a % b;
    if (re < 0) re += b;
    return re;
}

int dp[530][MAXK];

int main() {
    int T, G, K, R;
    scanf("%d", &T);

    while (T-- && scanf("%d%d%d", &G, &K, &R)) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1, in; i <= G; i++) {
            scanf("%d", &in);
            for (int j = 0; j < K; j++)
                if (dp[i - 1][j] > 0) {
                    dp[i][mod(j + in, K)] += dp[i - 1][j];
                    dp[i][mod(j + in, K)] %= M;
                    dp[i][mod(j - in, K)] += dp[i - 1][j];
                    dp[i][mod(j - in, K)] %= M;
                }
        }
        printf("%d\n", dp[G][R]);
    }
}
