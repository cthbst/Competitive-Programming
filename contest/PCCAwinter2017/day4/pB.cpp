#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 20004;
const int INF = 1<<29;

int N;
vector<int> G[MAXN];

int best_center;
int best_max_sub;

int dfs(int u,int fa);
void input();

int main(){
    int T; scanf("%d",&T);

    while (T-- && scanf("%d",&N)){
        input();

        best_max_sub = INF;
        dfs(1,1);

        printf("%d %d\n", best_center, best_max_sub);
    }
}

int dfs(int u, int fa){
    int max_sub=0;
    int sz=1;
    for (int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if (v==fa)continue;
        int szv = dfs(v,u);
        sz+=szv;
        max_sub = max(max_sub,szv);
    }
    max_sub = max(max_sub,N-sz);
    if (max_sub<best_max_sub || max_sub==best_max_sub && u<best_center){
        best_center = u;
        best_max_sub = max_sub;
    }
    return sz;
}

void input(){
    for (int i=1; i<=N; i++){
        G[i].clear();
    }

    for (int i=0, u, v; i<N-1; i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
