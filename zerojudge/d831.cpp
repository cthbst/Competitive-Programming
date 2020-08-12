#include <stdio.h>

#include <algorithm>
using namespace std;

#define MAXN 1000000
int par[MAXN][2];

int root(int n) {
    if (par[n][0] == n) return n;
    return par[n][0] = root(par[n][0]);
}

int main() {
    int N, M;
    while (~scanf("%d%d", &N, &M)) {
        int Ans = 1;
        for (int i = 0; i < N; i++) par[i][0] = i, par[i][1] = 1;

        for (int i = 0, a, b; i < M; i++) {
            scanf("%d%d", &a, &b);
            root(a), root(b);

            if (par[a][0] != par[b][0]) {
                par[par[a][0]][1] += par[par[b][0]][1];
                par[par[b][0]][0] = par[a][0];
                if (par[par[a][0]][1] > Ans) Ans = par[par[a][0]][1];
            }
        }
        printf("%d\n", Ans);
    }
}
