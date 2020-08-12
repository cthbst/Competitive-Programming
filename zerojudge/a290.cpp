#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

#define MAXN 1010

int N, M;
bool vis[MAXN];
vector<int> next[MAXN];

void walk(int n) {
    for (int i = 0; i < next[n].size(); i++) {
        if (!vis[next[n][i]]) {
            vis[next[n][i]] = 1;
            walk(next[n][i]);
        }
    }
}

int main() {
    while (~scanf("%d%d", &N, &M)) {
        // init---------------------------------------------
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < MAXN; i++) next[i].clear();

        // input--------------------------------------------
        for (int i = 0, a, b; i < M; i++) {
            scanf("%d%d", &a, &b);
            next[a].push_back(b);
        }

        // DFS----------------------------------------------
        int S, E;
        scanf("%d%d", &S, &E);

        vis[S] = 1;
        walk(S);

        // output-------------------------------------------
        printf("%s\n", vis[E] ? "Yes!!!" : " No!!!");
    }
}
