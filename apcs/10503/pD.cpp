/* APCS 2016 March problem D */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

// 宣告要輸入的變數，每個點會連到的點用一個 vector 存
int n;
vector<int> G[MAXN];  // G[i] 是一個 vector，裡面存所有 i 會連到的點

int ans;

// 回傳 u 的高度
int dfs(int u, int fa) {
    int a = 0;  // u 的小孩中最高的
    int b = 0;  // u 的小孩中第二高的

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (v == fa) continue;  // 不可以往父親節點走

        int d = dfs(v, u);  // 計算 v 的高度
        if (d > a) {  // 比目前的最大值大，原本的最大變成第二大
            b = a;
            a = d;
        } else if (d > b) {  // 取代原本的第二
            b = d;
        }
    }
    // 最高點在 u 的最長路徑長度就是 a+b
    ans = max(ans, a + b);
    return a + 1;
}

int main() {
    // 輸入 n, 接著把邊輸入
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);  // u 可以走到 v
        G[v].push_back(u);  // v 可以走到 u
    }

    ans = 0;
    dfs(0, 0);
    cout << ans << '\n';
}
