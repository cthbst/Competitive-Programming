#include<bits/stdc++.h>
using namespace std ;

struct E { int u ,v ,w ,idx; };
bool operator < (const E& a ,const E&b ){ return a.w<b.w ; }

const int maxn = 200000 ;
int n,m ;
E e[maxn] ;

int fa[maxn] ,sz[maxn] ,dis[maxn] ;
int add[maxn] ;
long long mst=0 ;

int walk(int a ,int b ,int w ){
    int cap=0 ;
    while ( (fa[a]!=a || fa[b]!=b) && a!=b ){
        if (fa[b]==b || fa[a]!=a && sz[a]<=sz[b] )
            cap=max(cap,dis[a]) ,a=fa[a] ;
        else
            cap=max(cap,dis[b]) ,b=fa[b] ;
    }
    if (a==b)return w-cap ;
    if (sz[a]<sz[b])swap(a,b) ;
    sz[a]+=sz[b] ,fa[b]=a ,dis[b]=w ,mst+=w ;
    return 0 ;
}
int main(){
    scanf("%d%d",&n ,&m ) ;
    for (int i=0 ;i<m ;i++ ){
        scanf("%d%d%d",&e[i].u ,&e[i].v ,&e[i].w) ;
        --e[i].u ,--e[i].v ,e[i].idx=i ;
    }
    sort(e,e+m) ;
    for (int i=0 ;i<n ;i++ )
        fa[i]=i ,sz[i]=1 ;
    for (int i=0 ;i<m ;i++ )
        add[e[i].idx]=walk(e[i].u,e[i].v,e[i].w) ;
    for (int i=0 ;i<m ;i++ )
        printf("%I64d\n",mst+add[i]) ;
}
