#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1000007;

vector<int> dp;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    dp.resize(m + 1);
    fill(dp.begin(), dp.end(), 0);
    dp[0] = 1;

    for (int i = 0, ai; i < n; i++) {
        scanf("%d", &ai);
        int sum = 0;
        for (int j = m, k = m - 1; j >= 1; j--) {
            while (k >= j - ai && k >= 0) {
                sum += dp[k--];
                if (sum >= MOD) sum -= MOD;
                if (sum < 0) sum += MOD;
            }
            dp[j] = (dp[j] + sum) % MOD;
            sum -= dp[j - 1];
        }
        // for (int x:dp)printf("%d ",x) ;puts("") ;
    }
    printf("%d\n", dp[m]);
}
