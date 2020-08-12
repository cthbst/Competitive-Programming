#include <stdio.h>
#include <string.h>
int dp[105] = {0};
int max(int x, int y) {
    return x > y ? x : y;
}
int main() {
    int N, volume, value;
    while (~scanf("%d", &N)) {
        memset(dp, 0, sizeof(dp));

        while (N--) {
            scanf("%d%d", &volume, &value);

            for (int j = 100; j >= volume; j--)
                dp[j] = max(dp[j], dp[j - volume] + value);
        }
        printf("%d\n", dp[100]);
    }
}
