#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
int h[MAXN];  // h[i]; 節點 i 的高度
vector<int> G[MAXN];  // G[i]: 一個 vector<int> 紀錄節點 i 可以走到的節點的編號

// dfs 遞迴計算每個節點的高度
void dfs(int u) {
    h[u] = 0;

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (h[v] == -1) dfs(v);      // 如果沒走過先走看看
        h[u] = max(h[u], h[v] + 1);  // 跟新 u 個高度
    }
}

int main() {
    // 輸入樹結構
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            G[i].push_back(v);
        }
    }

    // 建出 h[]
    for (int i = 1; i <= n; i++) {
        h[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (h[i] == -1) dfs(i);
    }

    // 找出 root, 即高度最高的節點
    // H 是 h[i] 的總和
    int root = 1, H = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] > h[root]) {
            root = i;
        }
        H += h[i];
    }
    cout << root << '\n' << H << '\n';
}
