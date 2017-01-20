#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

const int MAXN = 20004;

int N;
vector<Edge> G[MAXN];
int dp[MAXN][3];

int ans[MAXN];

void dfs(int u, int fa){
    dp[u][0]=1;
    dp[u][1]=dp[u][2]=0;
    ans[u]=0;
    
    for (int i=0; i<(int)G[u].size(); i++){
        Edge e = G[u][i];
        if (e.v==fa)continue;
        
        dfs(e.v,u);

        dp[u][(0+e.w)%3]+=dp[e.v][0];
        dp[u][(1+e.w)%3]+=dp[e.v][1];
        dp[u][(2+e.w)%3]+=dp[e.v][2];

        
        ans[u] -=   dp[e.v][(0-e.w+3)%3]*dp[e.v][(0-e.w+3)%3] + 
                    dp[e.v][(1-e.w+3)%3]*dp[e.v][(2-e.w+3)%3] + 
                    dp[e.v][(2-e.w+3)%3]*dp[e.v][(1-e.w+3)%3];
    }
    ans[u] += dp[u][0]*dp[u][0] + dp[u][1]*dp[u][2] + dp[u][2]*dp[u][1];
}

int main(){
    scanf("%d",&N);
    int u, v, w;
    for (int i=1; i<N; i++){
        scanf("%d %d %d", &u, &v, &w);
        w%=3;
        G[u].push_back((Edge){u,v,w});
        G[v].push_back((Edge){v,u,w});
    }
    
    dfs(1,1);
    int a=N*N, b=0;
    for (int i=1; i<=N; i++){
        b += ans[i];
    }
    
    int d=__gcd(a,b);
    
    a/=d, b/=d;
    printf("%d/%d\n",b,a);
}
