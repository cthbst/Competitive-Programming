/* greedy */
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1030 ;
int n ; char G[2][maxn] ;

int solve(){
    cin >> n ;
    scanf("%s%s",G[0]+1 ,G[1]+1 ) ;
    G[0][0]=G[1][0]=G[0][n+1]=G[1][n+1]='X' ;

    int re=0 ;
    for (int i=1 ;i<=n ;i++ )if (G[0][i-1]=='X' && G[0][i]=='.' && G[0][i+1]=='X'){
        G[0][i]='X' ; re++ ;
        if (G[1][i]!='.')continue ;
        G[1][i]='X' ;
        for (int j=i+1 ;G[1][j]=='.' ;j++ )G[1][j]='X' ;
        for (int j=i-1 ;G[1][j]=='.' ;j-- )G[1][j]='X' ;
    }
    for (int i=1 ;i<=n ;i++ )if (G[1][i-1]=='X' && G[1][i]=='.' && G[1][i+1]=='X'){
        G[1][i]='X' ; re++ ;
        if (G[0][i]!='.')continue ;
        G[0][i]='X' ;
        for (int j=i+1 ;G[0][j]=='.' ;j++ )G[0][j]='X' ;
        for (int j=i-1 ;G[0][j]=='.' ;j-- )G[0][j]='x' ;
    }
    for (int i=1 ;i<=n ;i++ )if (G[0][i]=='.'){
        re++ ;
        while (G[0][i]=='.')G[0][i++]='X' ;
    }
    for (int i=1 ;i<=n ;i++ )if (G[1][i]=='.'){
        re++ ;
        while (G[1][i]=='.')G[1][i++]='X' ;
    }
    return re ;
}


int main(){
    freopen("high_security.txt","r",stdin) ;
    freopen("pB_out.txt","w",stdout) ;
    int T ; cin >>T ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %d\n",t ,solve() ) ;
    }
}
