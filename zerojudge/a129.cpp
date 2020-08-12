#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};
vector<Edge> edges;

const int maxN = 100030;
int fa[maxN];
int root(int x) {
    if (fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}

const int INF = 1 << 30;
int near[maxN], len[maxN];

int main() {
    int V, E;
    while (~scanf("%d%d", &V, &E)) {
        // input -------------
        for (int i = 0; i < V; i++) {
            fa[i] = i;
        }
        edges.resize(E);
        for (Edge &e : edges) {
            scanf("%d%d%d", &e.u, &e.v, &e.w);
        }

        // MST ---------------
        int Group = V;
        long long ans = 0;

        while (Group > 1 && edges.size() > 0) {
            for (int i = 0; i < V; i++) {
                near[i] = i;
                len[i] = INF;
            }

            int nz = 0;
            for (Edge e : edges) {
                int u = root(e.u), v = root(e.v);
                if (u == v) continue;
                edges[nz++] = e;
                if (len[u] > e.w) len[u] = e.w, near[u] = v;
                if (len[v] > e.w) len[v] = e.w, near[v] = u;
            }
            edges.resize(nz);
            // bool update=0 ;
            for (int u = 0; u < V; u++) {
                if (fa[u] != u) continue;
                if (near[u] == u) continue;
                // update=1 ;
                fa[root(near[u])] = u;
                Group--;
                ans += len[u];
            }
            // if (!update)break ;
        }

        // output ------------
        if (Group > 1)
            puts("-1");
        else
            printf("%lld\n", ans);
    }
}
