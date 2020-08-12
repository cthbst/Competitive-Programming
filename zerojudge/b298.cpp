#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

const int MaxN = 10030;
vector<int> fa[MaxN];
bool problem[MaxN];
bool check[MaxN];

void DFS(int x) {
    if (check[x]) return;
    check[x] = 1;
    bool walk = 0;
    for (int i = 0; i < fa[x].size(); i++) {
        if (!check[fa[x][i]]) DFS(fa[x][i]);
        if (problem[fa[x][i]]) problem[x] = 1;
    }
}
int main() {
    int N, M, L, Q;

    while (~scanf("%d%d%d%d", &N, &M, &L, &Q)) {
        // init --------------
        for (int i = 1; i <= N; i++) fa[i].clear();
        memset(problem, 0, sizeof(problem));
        memset(check, 0, sizeof(check));

        // join --------------
        for (int i = 0, a, b; i < M; i++) {
            scanf("%d%d", &a, &b);
            fa[b].push_back(a);
        }

        // problem -----------
        for (int i = 0, p; i < L; i++) {
            scanf("%d", &p);
            problem[p] = 1;
            check[p] = 1;
        }

        // query -------------
        for (int i = 0, q; i < Q; i++) {
            scanf("%d", &q);
            if (!check[q]) DFS(q);
            if (!problem[q])
                puts("YA~~");
            else
                puts("TUIHUOOOOOO");
        }
    }
}
