#include <stdio.h>

typedef unsigned long long int LL;

int main() {
    // set dp() --------------
    LL dp[130][130];
    for (int i = 0; i <= 100; i++) dp[1][i] = i + 1, dp[i][0] = 1;

    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= 63; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        }
    }
    // solve -----------------
    LL K, N;

    while (scanf("%llu%llu", &K, &N) && K != 0 && N != 0) {
        if (N > dp[K][63])
            printf("More than 63 trials needed.\n");
        else {
            int L = 0, R = 63;
            while (L != R) {
                int M = (L + R) / 2;
                if (dp[K][M] < N)
                    L = M + 1;
                else
                    R = M;
            }
            printf("%d\n", L);
        }
    }
}
