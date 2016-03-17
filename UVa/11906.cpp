#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100 ;
int R ,C ,N ,M ,Q ;
int G[maxn][maxn] ;

void solve(){
    scanf("%d%d%d%d%d",&R ,&C ,&N ,&M ,&Q ) ;
    for (int i=0 ;i<R ;i++ )for (int j=0 ;j<C ;j++ )G[i][j]=1 ;
    for (int i=0 ,x ,y ;i<Q ;i++ ){
        scanf("%d%d",&x ,&y ) ;
        G[x][y]=0 ;
    }
    int dx[8]={N,N,-N,-N,M,-M,M,-M} ;
    int dy[8]={M,-M,M,-M,N,N,-N,-N} ;
    queue< pair<int,int> >que ;
    que.push(make_pair(0,0)) ;
    int even=0 ,odd=0 ;
    while (!que.empty()){
        int x = que.front().first ,y = que.front().second ;
        que.pop() ;
        G[x][y]=2 ;
        set< pair<int,int> > S ;
        for (int i=0 ;i<8 ;i++ ){
            int nx=x+dx[i] ,ny=y+dy[i] ;
            if (nx<0 || ny<0 || nx>=R || ny>=C )continue ;
            if (G[nx][ny]==0)continue ;
            auto aa = make_pair(nx,ny) ;
            S.insert(aa) ;
            if (G[nx][ny]==1)que.push(aa) ,G[nx][ny]=2 ;
        }
        S.size()%2==0?odd++:even++ ;
    }
    printf("%d %d\n",odd ,even ) ;
}

int main(){
    freopen("in.txt","r",stdin) ;
    int T ; scanf("%d",&T ) ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case %d: ",t ) ;
        solve() ;
    }
}
