#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxN = 10030;

vector<int> Ga[maxN];
bool touched[maxN];

int dfs_time;
int tin[maxN], low[maxN];
int sta[maxN], top;
bool insta[maxN];
int SCC[maxN];

vector<int> Gb[maxN];
int din[maxN];

void dfs(int u) {
    tin[u] = low[u] = ++dfs_time;
    sta[top++] = u, insta[u] = 1;

    for (int v : Ga[u]) {
        if (tin[v] == 0) dfs(v);
        if (insta[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == tin[u]) {
        int v;
        do {
            v = sta[--top];
            insta[v] = 0;
            SCC[v] = u;
        } while (v != u);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    int N, M, L;
    while (T-- && scanf("%d%d%d", &N, &M, &L)) {
        for (int i = 1; i <= N; i++) Ga[i].clear();
        // input -----------------
        for (int i = 0, u, v; i < M; i++) {
            scanf("%d%d", &u, &v);
            Ga[u].push_back(v);
        }
        memset(touched, 0, sizeof(touched));
        for (int i = 0, t; i < L; i++) {
            scanf("%d", &t);
            touched[t] = 1;
        }
        // SCC -------------------
        dfs_time = 0;
        memset(tin, 0, sizeof(tin));
        top = 0;
        memset(insta, 0, sizeof(insta));

        for (int i = 1; i <= N; i++)
            if (tin[i] == 0) {
                dfs(i);
            }
        // DAG ---------------
        for (int i = 1; i <= N; i++) Gb[i].clear();
        memset(din, 0, sizeof(din));
        for (int u = 1; u <= N; u++) {
            for (int v : Ga[u]) {
                if (SCC[u] == SCC[v]) continue;
                Gb[SCC[u]].push_back(SCC[v]);
                din[SCC[v]]++;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (touched[i]) touched[SCC[i]] = 1;
        }

        queue<int> que;
        for (int i = 1; i <= N; i++) {
            if (din[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : Gb[u]) {
                if (touched[u]) touched[v] = 1;
                din[v]--;
                if (din[v] == 0) que.push(v);
            }
        }
        // output ------------
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (touched[SCC[i]]) ans++;
        }
        printf("%d\n", ans);
    }
}
