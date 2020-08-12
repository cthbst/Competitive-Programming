#include <stdio.h>
#include <string.h>

long long int dp[13][130], fa[13][130];

int mod(int a, int b) {
    a %= b;
    if (a < 0) return a + b;
    return a;
}

int main() {
    //	freopen("test.txt","r",stdin) ;
    //	freopen("out.txt","w",stdout) ;
    int M, N;
    while (~scanf("%d%d", &M, &N)) {
        // input -------------
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%lld", &dp[i][j]);
            }
        }

        // dp ---------------
        memset(fa, -1, sizeof(fa));

        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                int t = mod(j - 1, M);
                for (int k = 0; k <= 1; k++) {
                    int v = mod(j + k, M);
                    if (dp[v][i + 1] < dp[t][i + 1] ||
                        (dp[v][i + 1] == dp[t][i + 1] && v < t)) {
                        t = v;
                    }
                }
                dp[j][i] += dp[t][i + 1];
                fa[j][i] = t;
            }
        }
        // output ------------
        int w = 0, t = 0, S;
        for (int i = 1; i < M; i++)
            if (dp[i][0] < dp[t][0]) t = i;
        S = t;
        printf("");
        while (t >= 0) {
            printf("%s%d", w > 0 ? " " : "", t + 1);
            t = fa[t][w++];
        }

        printf("\n%lld\n", dp[S][0]);
    }
}
