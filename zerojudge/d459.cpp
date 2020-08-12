#include <stdio.h>

#include <vector>
using namespace std;

const int maxN = 20030;
int dp[maxN];
vector<int> E[maxN];

void dfs(int u, int fa) {
    dp[u] = 1;

    for (int v : E[u])
        if (v != fa) {
            dfs(v, u);
            dp[u] += dp[v];
        }
}

int main() {
    // input -----------------
    int N;
    scanf("%d", &N);
    for (int i = 1, u, v; i < N; i++) {
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    // dp --------------------
    dfs(1, 1);

    // output ----------------
    for (int i = 1; i <= N; i++) {
        printf("%5d-%5d\n", i, dp[i]);
    }
}
