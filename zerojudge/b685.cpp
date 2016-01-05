#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
const LL MOD = 1000007 ;

const int maxn = 1001 ;
LL dp[maxn][maxn] ;

void build_dp(){
    memset(dp,0,sizeof(dp)) ;
    dp[0][0]=1 ;
    for (LL i=1 ;i<maxn ;i++ ){
        for (LL j=1 ;j<=i ;j++ ){
            dp[i][j] = (dp[i-1][j]*(i-1)+dp[i-1][j-1])%MOD ;
        }
    }
}

//disjoin set ---------------
int fa[maxn] ,G ,circle ;
void disjoin_set_init(int n ){
    G=n ,circle=0 ;
    for (int i=1 ;i<=n ;i++ )fa[i]=i ;
}
int root(int x){
    if (fa[x]==x)return x ;
    return fa[x]=root(fa[x]) ;
}
void Union(int u ,int v ){
    G-- ;
    u=root(u) ,v=root(v) ;
    if (u==v)circle++ ;
    else fa[u]=v ;
}

int main(){
    build_dp() ;

    int T ; scanf("%d",&T ) ;

    int n ,m ;
    while (T-- && scanf("%d%d",&n ,&m ) ){
        disjoin_set_init(n) ;
        for (int i=1 ,pi ;i<=n ;i++ ){
            scanf("%d",&pi ) ;
            if (pi!=0)Union(i,pi) ;
        }
        if (m-circle<0)puts("0") ;
        else printf("%lld\n",dp[G][m-circle]) ;
    }
}
