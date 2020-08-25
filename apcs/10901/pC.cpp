#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;

int n, L, pos[MAXN], h[MAXN];
int prev_ele[MAXN];
int next_ele[MAXN];
bool alive[MAXN];

int find_prev(int x) {
    if (prev_ele[x] == x) return x;
    return prev_ele[x] = find_prev(prev_ele[x]);
}

int find_next(int x) {
    if (next_ele[x] == x) return x;
    return next_ele[x] = find_next(next_ele[x]);
}

void init() {
    cin >> n >> L;
    for (int i = 1; i <= n; i++) cin >> pos[i];
    for (int i = 1; i <= n; i++) cin >> h[i];

    for (int i = 0; i <= n + 1; i++) {
        prev_ele[i] = i;
        next_ele[i] = i;
        alive[i] = true;
    }
    pos[0] = 0;
    pos[n + 1] = L;
}

bool ok(int x) {
    if (!alive[x]) return false;

    if (pos[find_prev(x - 1)] <= pos[x] - h[x]) return true;
    if (pos[find_next(x + 1)] >= pos[x] + h[x]) return true;
    return false;
}

void solve() {
    int cnt = 0, max_h = 0;
    queue<int> que;
    for (int i = 1; i <= n; i++) que.push(i);

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        if (!ok(u)) continue;
        alive[u] = false;
        cnt++;
        max_h = max(max_h, h[u]);
        prev_ele[u] = find_prev(u - 1);
        next_ele[u] = find_next(u + 1);
        if (prev_ele[u] >= 1) que.push(prev_ele[u]);
        if (next_ele[u] <= n) que.push(next_ele[u]);
    }
    cout << cnt << '\n' << max_h << '\n';
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    solve();
}
