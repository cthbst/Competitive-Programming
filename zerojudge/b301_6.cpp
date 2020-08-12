#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

const int maxN = 10030;
vector<int> E[maxN];

int LCA[maxN][20];
int tin[maxN], tout[maxN], TIME = 0;
void build_LCA(int fa, int x) {
    tin[x] = TIME++;

    LCA[x][0] = fa;
    for (int i = 1; i <= 16; i++) {
        LCA[x][i] = LCA[LCA[x][i - 1]][i - 1];
    }
    for (int v : E[x]) {
        if (v == fa) continue;
        build_LCA(x, v);
    }
    tout[x] = TIME++;
}

bool under(int top, int down) {
    return tin[top] <= tin[down] && tout[down] <= tout[top];
}

int query(int u, int v) {
    if (under(u, v)) return u;
    if (under(v, u)) return v;
    int w = v;
    for (int i = 16; i >= 0; i--) {
        if (under(LCA[w][i], u))
            continue;
        else
            w = LCA[w][i];
    }
    return LCA[w][0];
}

int main() {
    // input -----------------
    int N, Q;
    scanf("%d%d", &N, &Q);

    for (int i = 0, u, v; i < N; i++) {
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    // LCA -------------------
    build_LCA(0, 0);

    // query -----------------
    int ca, cb, a, b;
    while (Q-- && scanf("%d%d%d%d", &a, &b, &ca, &cb)) {
        if (under(cb, ca) == 1) swap(ca, cb);
        int c = query(a, b);

        if (query(cb, a) == cb && query(cb, b) == c) {
            puts("GO");
        } else if (query(cb, a) == c && query(cb, b) == cb) {
            puts("GO");
        } else {
            puts("STOP");
        }
    }
}
