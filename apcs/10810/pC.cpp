#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;
const int INF = 1e9 + 7;

int n, P, L, R;
int S[MAXN];
int ans[MAXN];

void init() {
    cin >> n >> P >> L >> R;
    for (int i = 0; i < n; i++) cin >> S[i];
}

void solve() {
    fill(ans, ans + n, -1);
    
    queue<int> que;
    que.push(0);
    ans[0] = 0;
    
    while (!que.empty()){
        int u = que.front();
        que.pop();
        if (u + R < n && 0 <= S[u + R] && S[u + R] < n) {
            int v = S[u + R];
            if (ans[v] == -1) {
                ans[v] = ans[u] + 1;
                que.push(v);
            }
        }
        if (u - L >= 0 && 0 <= S[u - L] && S[u - L] < n) {
            int v = S[u - L];
            if (ans[v] == -1) {
                ans[v] = ans[u] + 1;
                que.push(v);
            }
        }   
    }
    
    cout << ans[P] << '\n';
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    solve();
}
