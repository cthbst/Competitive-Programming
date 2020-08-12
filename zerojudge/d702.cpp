#include <stdio.h>
#define MAXN 1001
short dp[MAXN][400];
int top[MAXN];

void output(int n) {
    for (int i = top[n - 1] - 1; i >= 0; i--) printf("%d", dp[n - 1][i]);
    printf("\n");
}

int main() {
    top[0] = top[1] = top[2] = 1;
    dp[0][0] = dp[1][0] = dp[2][0] = 1;

    // dp---------------------------------------------------
    for (int i = 3; i < MAXN; i++) {
        top[i] = top[i - 2];

        int c = 0;
        for (int j = 0; j < top[i - 2]; j++) {
            dp[i][j] = dp[i - 2][j] + dp[i - 3][j] + c;
            c = dp[i][j] / 10;
            dp[i][j] %= 10;
        }

        while (c != 0) {
            dp[i][top[i]++] = c % 10;
            c /= 10;
        }
    }
    // input------------------------------------------------
    int n;
    while (~scanf("%d", &n)) {
        output(n);
    }
}
