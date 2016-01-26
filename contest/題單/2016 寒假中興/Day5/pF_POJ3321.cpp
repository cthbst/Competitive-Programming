#include<stdio.h>
#include<string.h>
//#include<vector>
//using namespace std ;

const int maxn = 100001 ;
int n ;
//vector<int> G[maxn] ;
int G[maxn][100] ,sz[maxn] ;
int I[maxn] ,O[maxn] ,time_tag=0 ;

void dfs(int u ,int fa ){
    I[u] = time_tag++ ;
    for (int i=sz[u]/*G[u].size()*/-1 ;i>=0 ;i-- )
        if (G[u][i]!=fa)dfs(G[u][i],u) ;
    O[u] = time_tag-1 ;
}

//segment tree --------------
#define lc(o) (o<<1)
#define rc(o) (o<<1|1)
#define pull(o) (seg[o]=seg[lc(o)]+seg[rc(o)])
int seg[maxn*4] ;
void build(int o ,int l ,int r ){
    if (l==r)seg[o]=1 ;
    else {
        int m = (l+r)>>1 ;
        build(lc(o),l,m) ;
        build(rc(o),m+1,r) ;
        pull(o) ;
    }
}
void update(int o,int l ,int r ,int k){
    if (r<k || k<l )return ;
    if (l==r)seg[o]=!seg[o] ;
    else {
        int m = (l+r)>>1 ;
        update(lc(o),l,m,k) ;
        update(rc(o),m+1,r,k) ;
        pull(o) ;
    }
}
int query(int o ,int l ,int r ,int L ,int R ){
    if (R<l || r<L)return 0 ;
    if (L<=l && r<=R )return seg[o] ;
    int m=(l+r)>>1 ;
    return query(lc(o),l,m,L,R)+query(rc(o),m+1,r,L,R) ;
}

int main(){
    memset(sz,0,sizeof(sz)) ;
    //input -----------------
    scanf("%d",&n ) ;
    for (int i=1 ,u ,v ;i<n ;i++ ){
        scanf("%d%d",&u ,&v ) ;
        G[u][ sz[u]++ ]=v ;
        G[v][ sz[v]++ ]=u ;
    }
    dfs(1,1) ;
    build(1,0,n-1) ;
    //query -----------------
    int Q ,pos ; scanf("%d",&Q ) ;
    char cmd[10] ;

    while (Q-- && scanf("%s%d",cmd ,&pos )){
        if (cmd[0]=='Q')
            printf("%d\n",query(1,0,n-1,I[pos],O[pos])) ;
        else    //cmd[0] = C
            update(1,0,n-1,I[pos]) ;
    }
}
