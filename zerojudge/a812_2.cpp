#include <stdio.h>
#include <string.h>

typedef unsigned long long int LL;

int main() {
    int X, Y, M;
    while (~scanf("%d%d%d", &X, &Y, &M)) {
        LL dp[2][X + 1][M];

        // init --------------
        memset(dp[0], 0, sizeof(dp[0]));
        for (int i = 0; i <= X; i++) dp[0][i][0] = 1;

        // dp ----------------
        for (int i = 1; i <= Y; i++) {
            int w = i & 1, l = (i + 1) & 1;
            memset(dp[w], 0, sizeof(dp[w]));

            for (int j = i; j <= X; j++) {
                for (int k = 0; k < M; k++)
                    dp[w][j][(2 * k + 1) % M] += dp[l][j][k];
            }
            for (int j = i + 1; j <= X; j++) {
                int mid = M >> 1;
                for (int k = 0; k < mid; k++)
                    dp[w][j][2 * k] += dp[w][j - 1][k];
                for (int k = mid; k < M; k++)
                    dp[w][j][(2 * k) % M] += dp[w][j - 1][k];
                /*
                for (int k=0 ;k<M ;k++ )
                    dp[w][j][(2*k)%M]+=dp[w][j-1][k] ;
                */
            }
        }
        // output ------------
        LL Ans = 0;
        for (int i = 1, y = Y & 1; i < M; i++) Ans += i * dp[y][X][i];
        printf("%lld\n", Ans);
    }
}
