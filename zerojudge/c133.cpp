#include<bits/stdc++.h>
using namespace std ;

const int maxn = 4 ;
int n ,w[maxn+5][maxn+5] ,ans ;
char G[maxn+5][maxn+5] ;

void dfs(int d ,int cnt ){
    ans=max(ans,cnt) ;
    if (d==n*n)return ;
    int x=d/n ,y=d%n ;
    dfs(d+1,cnt) ;
    if (G[x][y]=='X'||w[x][y]!=0)return ;
    w[x][y]++ ;
    for (int i=x+1 ;i<n && G[i][y]!='X';i++)w[i][y]++ ;
    for (int i=x-1 ;i>=0&& G[i][y]!='X';i--)w[i][y]++ ;
    for (int i=y+1 ;i<n && G[x][i]!='X';i++)w[x][i]++ ;
    for (int i=y-1 ;i>=0&& G[x][i]!='X';i--)w[x][i]++ ;
    dfs(d+1,cnt+1) ;
    w[x][y]-- ;
    for (int i=x+1 ;i<n && G[i][y]!='X';i++)w[i][y]-- ;
    for (int i=x-1 ;i>=0&& G[i][y]!='X';i--)w[i][y]-- ;
    for (int i=y+1 ;i<n && G[x][i]!='X';i++)w[x][i]-- ;
    for (int i=y-1 ;i>=0&& G[x][i]!='X';i--)w[x][i]-- ;
}

void solve(){
    memset(w,0,sizeof(w)) ;
    for (int i=0 ;i<n ;i++ )scanf("%s",G[i]) ;
    ans=0 ;
    dfs(0,0) ;
    printf("%d\n",ans) ;
}

int main(){
    while (scanf("%d",&n) && n>0 )solve() ;
}
