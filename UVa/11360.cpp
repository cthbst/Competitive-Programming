#include<bits/stdc++.h>
using namespace std ;

const int maxn = 50 ;
int n ,m ;
char G[maxn][maxn] ;

void solve(){
    scanf("%d",&n ) ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%s",G[i]) ;
        for (int j=0 ;j<n ;j++ )G[i][j]-='0' ;
    }
    scanf("%d",&m ) ; string cmd ;
    int a ,b ;
    while (m-- && cin >> cmd ){
        if (cmd==(string)"row" && scanf("%d%d",&a ,&b )){
            a-- ,b-- ;
            for (int i=0 ;i<n ;i++ )swap(G[a][i],G[b][i]) ;
        }
        else if (cmd==(string)"col" && scanf("%d%d",&a ,&b )){
            a-- ,b-- ;
            for (int i=0 ;i<n ;i++ )swap(G[i][a],G[i][b]) ;
        }
        else if (cmd==(string)"inc"){
            for (int i=0 ;i<n ;i++ )
                for (int j=0 ;j<n ;j++ )
                    G[i][j]=(G[i][j]+1)%10 ;
        }
        else if (cmd==(string)"dec"){
            for (int i=0 ;i<n ;i++ )
                for (int j=0 ;j<n ;j++ )
                    G[i][j]=(G[i][j]+9)%10 ;
        }
        else {
            for (int i=0 ;i<n ;i++ )
                for (int j=i+1 ;j<n ;j++ )
                    swap(G[i][j],G[j][i]) ;
        }
    }
    for (int i=0 ;i<n ;i++ ){
        for (int j=0 ;j<n ;j++ )G[i][j]+='0' ;
        puts(G[i]) ;
    }
}

int main(){
    int T ;scanf("%d",&T ) ;

    for (int i=1 ;i<=T ;i++ ){
        printf("Case #%d\n",i ) ;
        solve() ;
        puts("") ;
    }
}
