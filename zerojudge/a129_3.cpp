#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(Edge o) const {
        return w < o.w;
    }
};
vector<Edge> edges;

const int maxN = 100030;
int fa[maxN];
int root(int x) {
    if (fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}

int main() {
    int V, E;
    while (~scanf("%d%d", &V, &E)) {
        for (int i = 0; i < V; i++) {
            fa[i] = i;
        }
        edges.resize(E);
        for (Edge &e : edges) {
            scanf("%d%d%d", &e.u, &e.v, &e.w);
        }
        sort(edges.begin(), edges.end());
        int Group = V;
        long long ans = 0;
        for (Edge e : edges) {
            if (Group == 1) break;
            int u = root(e.u), v = root(e.v);
            if (u == v) continue;
            fa[u] = v, Group--;
            ans += e.w;
        }
        if (Group > 1)
            puts("-1");
        else
            printf("%lld\n", ans);
    }
}
