#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20004;

int n;
vector<int> G[MAXN];
int sub[MAXN];
long long cnt[MAXN];

void input() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void build_sub(int u, int fa) {
    sub[u] = 1;
    for (int v : G[u])
        if (v != fa) {
            build_sub(v, u);
            sub[u] += sub[v];
        }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        cnt[i] = (long long)(n - sub[i]) * (sub[i] - 1);

        for (int v : G[i])
            if (sub[v] < sub[i]) {
                cnt[i] += (long long)(n - 1 - sub[v]) * sub[v];
            }

        cnt[i] /= 2;
    }
}

void output() {
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] > cnt[ans]) ans = i;
    }
    printf("%d %lld\n", ans, cnt[ans]);
}

int main() {
    input();
    build_sub(1, 1);
    solve();
    output();
}
