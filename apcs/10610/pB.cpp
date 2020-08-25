#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n, k;
string s;
int pre[MAXN];    // pre[i]: s[0~i] 的小寫字母個數
int dp[MAXN][2];  // dp[i][0]: s[i]為結尾且是大寫的交錯段數
                  // dp[i][1]: s[i]為結尾且是小寫的交錯段數

int main() {
    cin >> k;
    cin >> s;

    // 建立 pre[]
    n = s.size();
    for (int i = 0, sum = 0; i < n; i++) {
        if ('a' <= s[i] && s[i] <= 'z') sum++;
        pre[i] = sum;
    }

    // 初始化 dp 邊界
    for (int i = 0; i < k; i++) {
        dp[i][0] = dp[i][1] = 0;
    }

    // 計算 dp 轉移
    for (int i = k; i < n; i++) {
        dp[i][0] = dp[i][1] = 0;

        if (pre[i] - pre[i - k] == 0) {
            dp[i][0] = dp[i - k][1] + 1;
        }
        if (pre[i] - pre[i - k] == k) {
            dp[i][1] = dp[i - k][0] + 1;
        }
    }

    // 輸出答案 ans = 所有 dp[i][j] 中的最大值
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans * k << '\n';  // 段數 * k 才是長度
}
