#include <stdio.h>

#include <vector>
using namespace std;

const int maxn = 10010;
vector<int> E[maxn];

void dfs(int u, int FA) {
    for (int v : E[u]) {
        if (v == FA) continue;
        dfs(v, u);
    }
    E[u].clear();
    E[u].push_back(FA);
}

int ca, cb;
bool query(int a) {
    bool visCa = 0, visCb = 0;
    while (1) {
        if (a == ca) visCa = 1;
        if (a == cb) visCb = 1;
        if (a == 0) break;
        a = E[a][0];
    }
    return visCa && visCb;
}

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 0, u, v; i < N; i++) {
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(0, 0);
    // query -----------------
    int a, b;
    while (Q-- && scanf("%d%d%d%d", &a, &b, &ca, &cb)) {
        puts(query(a) ^ query(b) ? "GO" : "STOP");
    }
}
