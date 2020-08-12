#include <stdio.h>

int dp[1000030];

int main() {
    // set dp ----------------
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= 1000000; i++) {
        dp[i] = dp[i - dp[i - 1]] + dp[i - 1 - dp[i - 2]];
    }

    // solve -----------------
    int N;
    while (~scanf("%d", &N) && N != 0) {
        printf("%d\n", dp[N]);
    }
}
