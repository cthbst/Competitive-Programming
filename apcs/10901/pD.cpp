#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000006;
int n, m;
int lc[MAXN], rc[MAXN];  // left_child, right_child
int w[MAXN];
int q[MAXN];

void init() {
    cin >> n >> m;
    for (int i = n; i <= 2 * n - 1; i++) cin >> w[i];
    for (int i = 0; i < m; i++) cin >> q[i];
    for (int i = 1; i < n; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        lc[x] = l;
        rc[x] = r;
    }
}

void dfs(int x) {
    if (lc[x] == 0) return;

    dfs(lc[x]);
    dfs(rc[x]);
    w[x] = w[lc[x]] + w[rc[x]];
}

void update(int x, int add) {
    w[x] += add;
    if (lc[x] == 0) {
        cout << x << ' ';
        return;
    }

    if (w[lc[x]] <= w[rc[x]]) {
        update(lc[x], add);
    } else {
        update(rc[x], add);
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(1);
    for (int i = 0; i < m; i++) {
        update(1, q[i]);
    }
}
