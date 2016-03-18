#include<bits/stdc++.h>
using namespace std ;

const int n = 8 ;
const int maze = (1<<n)-1 ;
int w[n][n] ,ans ;

void dfs(int sum ,int d ,int l ,int m ,int r ){
    if (d==n){
        ans=max(ans,sum) ;
        return ;
    }
    int S = l&m&r ;
    for (int i=0 ;i<n ;i++ )if (S&(1<<i)){
        l^=(1<<i) ,m^=(1<<i) ,r^=(1<<i) ;
        dfs(sum+w[d][i]
            ,d+1
            ,(l<<1)|1
            ,m
            ,(r>>1)|(1<<(n-1))
        );
        l^=(1<<i) ,m^=(1<<i) ,r^=(1<<i) ;
    }
}

void solve(){
    for (int i=0 ;i<n ;i++ ){
        for (int j=0 ;j<n ;j++ ){
            scanf("%d",&w[i][j]) ;
        }
    }
    ans=0 ;
    dfs(0,0,maze,maze,maze) ;
    printf("%d\n",ans) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while (T--) solve() ;
}
