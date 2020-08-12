#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;

const int maxN = 130;

int a[maxN][maxN];
int dp[maxN];
int main() {
    int N;
    while (~scanf("%d", &N)) {
        // input -------------
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        // dp ----------------
        int ans = 0;
        for (int l = 1; l <= N; l++) {
            memset(dp, 0, sizeof(dp));
            for (int r = l; r <= N; r++) {
                for (int i = 1; i <= N; i++) {
                    dp[i] += a[r][i];
                }
                int sum = dp[1];
                ans = max(ans, sum);
                for (int i = 2; i <= N; i++) {
                    sum = max(sum + dp[i], dp[i]);
                    ans = max(ans, sum);
                }
            }
        }
        // output ------------
        printf("%d\n", ans);
    }
}
