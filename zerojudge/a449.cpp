#include <stdio.h>

struct str {
    int t, u;
};
str dp[2030];

#define INF 1 << 30

int main() {
    int N, K, M;

    while (~scanf("%d%d%d", &N, &K, &M)) {
        // init --------------
        for (int i = 1; i <= N; i++) dp[i] = {N + 1, INF};
        dp[0] = (str){1, 0};

        // dp ----------------
        for (int i = 0, wi; i < N; i++) {
            scanf("%d", &wi);
            if (wi > M) continue;

            for (int j = i; j >= 0; j--) {
                if (dp[j].u + wi > M) {
                    if (dp[j].t + 1 < dp[j + 1].t ||
                        (dp[j].t + 1 == dp[j + 1].t && wi < dp[j + 1].u)) {
                        if (dp[j].t >= K) continue;
                        dp[j + 1] = (str){dp[j].t + 1, wi};
                    }
                } else {
                    if (dp[j].t < dp[j + 1].t || (dp[j].t == dp[j + 1].t &&
                                                  dp[j].u + wi < dp[j + 1].u)) {
                        dp[j + 1] = (str){dp[j].t, dp[j].u + wi};
                    }
                }
            }
        }
        // output ------------
        int Ans = N;
        for (int i = N; i >= 0; i--) {
            if (dp[i].t != N + 1) {
                Ans = i;
                break;
            }
        }

        printf("%d\n", Ans);
    }
}
