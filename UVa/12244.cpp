#include<bits/stdc++.h>
using namespace std ;

const int maxn = 50030 ;
int n ,G[maxn] ,din[maxn] ,sz[maxn] ,from[maxn] ;

int solve(){
    memset(din,0,sizeof(din)) ;
    scanf("%d",&n ) ;
    for (int i=1 ;i<=n ;i++ ){
        din[i]=0 ;
        sz[i]=0 ,from[i]=maxn ;
    }
    for (int i=0 ,u ,v ;i<n ;i++ ){
        scanf("%d%d",&u ,&v ) ;
        din[v]++ ;
        G[u]=v ;
    }
    queue<int> que ;
    for (int i=1 ;i<=n ;i++ )if (din[i]==0){
        que.push(i) ;
        from[i]=i ,sz[i]=1 ;
    }
    while (!que.empty()){
        int u = que.front() ; que.pop() ;
        int v = G[u] ;
        if (sz[v]<sz[u]+1 || sz[v]==sz[u]+1 && from[u]<from[v]){
            from[v]=from[u] ;
            sz[v]=sz[u]+1 ;
        }
        din[v]-- ;
        if (din[v]==0)que.push(v) ;
    }
    int ans=1 ,dis=0 ;
    for (int u=1 ;u<=n ;u++ )if(din[u]==1){
        int cir=1 ,v=G[u] ;
        while (v!=u)cir++ ,v=G[v] ;
        if (dis<cir || dis==cir && ans>u)dis=cir,ans=u ;
        do {
            int len = sz[v]+cir ;
            if (dis<len || dis==len && ans>from[v])dis=len,ans=from[v] ;
            din[v]-- ;
            v=G[v] ;
        }while (v!=u );
    }
    //printf("dis = %d\n",dis ) ;
    return ans ;
}

int main(){
    int T ;scanf("%d",&T ) ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case %d: %d\n",t ,solve()) ;
    }
}
