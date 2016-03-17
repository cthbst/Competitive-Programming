#include<bits/stdc++.h>
using namespace std ;

const int INF = 1<<29 ;
const int maxn = 530 ;
int n ,m ,d[maxn][maxn] ,dis[maxn] ,from[maxn] ;
bool used[maxn] ;

void Dijkstra(){
    dis[1]=0 ;
    for (int i=1 ;i<=n ;i++ ){
        int u=1 ;
        for (int j=1 ;j<=n ;j++ )if (!used[j]){
            if (used[u] || dis[u]>dis[j] ) u=j ;
        }
        used[u]=1 ;
        for (int j=1 ;j<=n ;j++ ){
            if ( dis[j] > dis[u] + d[u][j] ) from[j]=u ;
            dis[j]=min(dis[j],dis[u]+d[u][j]) ;
        }
    }
}

void solve(){
    //input -----------------
    for (int i=1 ;i<=n ;i++ ){
        for (int j=1 ;j<=n ;j++ )d[i][j]=INF ;
        d[i][i]=0 ,dis[i]=INF ,used[i]=0 ;
    }
    for (int i=0 ,u ,v ,t ;i<m ;i++ ){
        scanf("%d%d%d",&u ,&v ,&t ) ;
        d[u][v]=d[v][u]=min(d[u][v],t) ;
    }
    //solve -----------------
    Dijkstra() ;

    int lv=INF ,len=-1 ;
    for (int i=1 ;i<=n ;i++ ){
        if (len<dis[i] || len==dis[i] && i<lv)len=dis[i] ,lv=i ;
    }
    int la=INF ,lb=INF ,time=-1 ;
    for (int u=1 ;u<=n ;u++ )for (int v=u+1 ;v<=n ;v++ ){
        if (d[u][v]>=INF)continue ;
        int a=u ,b=v ; if (dis[a]>dis[b])swap(a,b);
        if (from[b]==a)continue ;
        int t = d[a][b]+dis[b]+dis[a] ;
        if (time<t)time=t,la=u ,lb=v ;
    }

    //output ----------------
    if (len*2>=time){
        printf("The last domino falls after %d.0 seconds, at key domino %d.\n",len ,lv ) ;
    }
    else {
        printf("The last domino falls after %.01f seconds, between key dominoes %d and %d.\n",0.5*time ,la ,lb ) ;
    }
}

int main(){
    //freopen("pB_in.txt","r",stdin) ;
    int Case=0 ;
    while (~scanf("%d%d",&n ,&m )){
        if (n==0 && m==0)return 0 ;
        printf("System #%d\n",++Case) ;
        solve() ;
        puts("") ;
    }
}
