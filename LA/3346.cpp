#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1030 ;
const int INF = maxn ;

int m ;
vector<int> G[maxn] ;
int black[maxn] ,cover[maxn] ,need[maxn] ;

int min(int a ,int b ,int c ){
    return min(a,min(b,c)) ;
}

void init(){
    for (int i=m+1 ;i>=1 ;i-- )G[i].clear() ;
}
void input(){
    for (int i=0 ,u ,v ;i<m ;i++ ){
        scanf("%d%d",&u ,&v ) ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
}

void dfs(int u ,int fa){
    black[u]=1 ,cover[u]=INF ,need[u]=0 ;
    if (G[u].size()==1)return ;

    int sum=0 ;
    for (int v:G[u])if (v!=fa){
        dfs(v,u) ;
        black[u]+=min(black[v],need[v]) ;
        need[u]+=cover[v] ;
        sum+=cover[v] ;
    }
    for (int v:G[u])if (v!=fa){
        cover[u]=min(cover[u],sum-cover[v]+black[v]) ;
    }
    //printf("u(%d) black= %d cover= %d need= %d\n",u ,black[u],cover[u],need[u]) ;
}

void solve(){
    init() ;
    input() ;
    G[1].push_back(0) ;
    dfs(1,0) ;
    printf("%d\n",min(black[1],cover[1])) ;
}

int main(){
    while (cin >> m && m!=0)solve() ;
}
