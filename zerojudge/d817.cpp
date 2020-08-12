#include <stdio.h>
#include <string.h>

char ans[5030][2000];
int dp[2000];

int main() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    ans[0][0] = '1';
    for (int i = 1; i <= 5000; i++) {
        for (int j = 0; j < 2000; j++) dp[j] *= 2;
        for (int j = 0; j < 1999; j++) dp[j + 1] += dp[j] / 10, dp[j] %= 10;
        int top = 1999;
        while (top > 0 && dp[top] == 0) top--;
        for (int j = 0; top >= 0; j++, top--) {
            ans[i][j] = dp[top] + '0';
        }
    }

    int n;
    while (~scanf("%d", &n)) {
        puts(ans[n]);
    }
}
