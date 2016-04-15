#include<bits/stdc++.h>
using namespace std ;

const int maxn = 10000 ;
int n ,dp[maxn][2] ;
vector<int> G[maxn] ;

void dfs(int u){
    dp[u][0]=0 ,dp[u][1]=1 ;
    for (int v:G[u])dfs(v) ;
    for (int v:G[u]){
        dp[u][0]+=dp[v][1] ;
        dp[u][1]+=min(dp[v][0],dp[v][1]) ;
    }
}

void solve(){
    scanf("%d",&n ) ;
    for (int i=0 ;i<n ;i++ )G[i].clear() ;

    for (int i=1 ,fa ;i<n ;i++ ){
        scanf("%d",&fa ) ;
        G[fa].push_back(i) ;
    }

    if (n==1){
        puts("1") ;
        return ;
    }
    dfs(0) ;
    printf("%d\n",min(dp[0][0],dp[0][1]) ) ;
}

int main(){
    int T ;scanf("%d",&T ) ;
    while (T--)solve() ;
}
