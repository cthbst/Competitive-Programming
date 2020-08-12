#include <stdio.h>

#include <algorithm>
using namespace std;

#define MAX 105
int A[MAX], B[MAX];
int dp[MAX][MAX];
int main() {
    int N1, N2, count = 0;

    while (scanf("%d%d", &N1, &N2) && N1 && N2) {
        // input------------------------------------------
        for (int i = 0; i < N1; i++) scanf("%d", &A[i]);
        for (int i = 0; i < N2; i++) scanf("%d", &B[i]);
        // LCS--------------------------------------------
        for (int i = 1; i <= N1; i++) {
            for (int j = 1; j <= N2; j++) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        // output------------------------------------------
        printf("Twin Towers #%d\nNumber of Tiles : %d\n", ++count, dp[N1][N2]);
    }
}
