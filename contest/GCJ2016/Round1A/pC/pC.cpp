#include<bits/stdc++.h>
using namespace std ;

const int maxn = 2000 ;

int n ,din[maxn] ,nex[maxn] ,dp[maxn] ;
bool live[maxn] ;

int dfs(int u){
    if (live[u]==0)return 0 ;
    live[u]=0 ;
    return dfs(nex[u])+1 ;
}

void solve(){
    memset(live,1,sizeof(live)) ;
    memset(din,0,sizeof(din)) ;

    scanf("%d",&n ) ;
    for (int u=1 ,v ;u<=n ;u++ ){
        scanf("%d",&v) ;
        nex[u]=v ;
        din[v]++ ;
        dp[u]=1 ;
    }
    queue<int> que ;
    for (int i=1 ;i<=n ;i++ )if (din[i]==0){
        que.push(i) ;
    }
    while (!que.empty()){
        int u = que.front() ;que.pop() ;
        live[u]=0 ;
        din[ nex[u] ]-- ;
        dp[ nex[u] ] = max(dp[ nex[u] ],dp[u]+1) ;
        if (din[ nex[u] ]==0)que.push(nex[u]) ;
    }
    int ans=0 ;
    for (int i=1 ;i<=n ;i++ )if (live[i]){
        ans=max(ans,dfs(i)) ;
    }
    int sum=0 ;
    for (int i=1 ;i<=n ;i++ )if (nex[ nex[i] ]==i){
        sum+=dp[i] ;
    }
    ans = max(ans,sum) ;
    //for (int i=1 ;i<=n ;i++ )printf("(%d)%d ",i ,dp[i]) ;
    printf("%d\n",ans ) ;
}
int main(){
    freopen("C-large.in","r",stdin) ;
    freopen("C-large_out.txt","w",stdout ) ;
    int T ; scanf("%d",&T ) ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: ",t ) ;
        solve() ;
    }
}
