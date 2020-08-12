#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

const int maxN = 1 << 16;
vector<int> E[maxN];

int dp[16][maxN];
int tin[maxN], TIME = 0, deep[maxN];

void dfs(int u) {
    tin[u] = TIME;
    dp[0][TIME++] = u;
    for (int v : E[u]) {
        dfs(v);
        dp[0][TIME++] = u;
    }
}
int Log(int x) {
    int s[] = {2, 4, 16, 256, 65536};
    int v[] = {1, 2, 4, 8, 16};
    int re = 0;
    for (int i = 4; i >= 0; i--) {
        if (x >= s[i]) {
            x >>= v[i];
            re += v[i];
        }
    }
    return re;
}

int LCA(int a, int b) {
    a = tin[a], b = tin[b];
    if (a > b) swap(a, b);
    int l = Log(b - a + 1);
    if (deep[dp[l][a]] < deep[dp[l][b - (1 << l) + 1]]) {
        return dp[l][a];
    } else {
        return dp[l][b - (1 << l) + 1];
    }
}
int main() {
    // input -----------------
    int N, Q;
    scanf("%d%d", &N, &Q);
    deep[1] = 1;
    for (int i = 1, v; i <= N; i++) {
        while (scanf("%d", &v) && v != 0) {
            E[i].push_back(v);
            deep[v] = deep[i] + 1;
        }
    }

    // build Sparse Table ----
    dfs(1);
    dp[0][TIME] = 0;
    for (int i = 1, j, t = 1; t <= TIME; i++, t <<= 1) {
        for (j = 0; dp[i - 1][j + t] != 0; j++) {
            dp[i][j] = (deep[dp[i - 1][j]] < deep[dp[i - 1][j + t]]
                            ? dp[i - 1][j]
                            : dp[i - 1][j + t]);
        }
        dp[i][j] = 0;
    }
    // query -----------------
    int a, b;
    while (Q-- && scanf("%d%d", &a, &b)) {
        int c = LCA(a, b);
        printf("%d %d\n", c, deep[a] + deep[b] - 2 * deep[c]);
    }
}
