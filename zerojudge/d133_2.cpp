#include <stdio.h>
#define MAX 30010
unsigned long long int dp[MAX];
int coin[5] = {1, 5, 10, 25, 50};
int main() {
    for (int i = 0; i < MAX; i++) dp[i] = 1;
    for (int i = 1; i < 5; i++) {
        for (int j = coin[i]; j < MAX; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    int n;
    while (~scanf("%d", &n)) {
        if (n < 5)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", dp[n],
                   n);
    }
}
