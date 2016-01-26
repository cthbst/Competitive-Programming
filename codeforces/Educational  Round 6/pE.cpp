#include<bits/stdc++.h>
using namespace std ;

const int maxn = 400001 ;
int n ,Q ;
long long color[maxn] ;
vector<int> G[maxn] ;
vector<int> T ;
int I[maxn] ,O[maxn] ,time_tag=0 ;


void out(long long x ){
    for (long long i = 1LL<<60 ;i>0 ;i>>=1 ){
        if (x&i)cout <<1 ;
        else cout <<0 ;
    }
    cout <<endl ;
}

void dfs(int u ,int fa ){
    I[u] = time_tag++ ;
    T.push_back(u) ;
    for (int v:G[u])if(v!=fa){
        dfs(v,u) ;
    }
    O[u] = time_tag++ ;
    T.push_back(u) ;
}

//segment tree --------------
struct Seg{
    long long c ;
    long long s ;
    Seg ():c(0),s(0) {}
};

Seg seg[maxn*16] ;

void build(int o ,int l ,int r ){
    if (l==r){
        seg[o].c = color[ T[l] ] ;
    }
    else {
        int m = (l+r)>>1 ;
        build(o<<1,l,m) ;
        build(o<<1|1,m+1,r) ;
        seg[o].c = seg[o<<1].c|seg[o<<1|1].c ;
    }
}

void push(int o ){
    if (seg[o].s==0)return ;
    seg[o].c = seg[o].s ;
    seg[o<<1].s = seg[o<<1|1].s = seg[o].s ;
    seg[o].s=0 ;
}
void set_color(int o ,int l ,int r ,int L ,int R ,long long nc ){
    push(o) ;
    if (R<l || r<L )return ;
    if (L<=l && r<=R){
        seg[o].s=nc ;
        push(o) ;
        return ;
    }
    int m = (l+r)>>1 ;
    set_color(o<<1,l,m,L,R,nc) ;
    set_color(o<<1|1,m+1,r,L,R,nc) ;
    seg[o].c = seg[o<<1].c | seg[o<<1|1].c ;
}
long long query (int o ,int l ,int r ,int L ,int R ){
    if (R<l || r<L )return 0LL ;
    push(o) ;
    if (L<=l && r<=R )return seg[o].c ;
    int m = (l+r)>>1 ;
    return query(o<<1,l,m,L,R)|query(o<<1|1,m+1,r,L,R) ;
}
int main(){
    //input -----------------
    cin >> n >> Q ;
    for (int i=1 ,ci ;i<=n ;i++ ){
        scanf("%d",&ci ) ;
        color[i] = (1LL<<ci) ;
    }
    for (int i=1 ,u ,v ;i<n ;i++ ){
        scanf("%d%d",&u ,&v ) ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    dfs(1,1) ;
    build(1,0,2*n-1) ;
    //query -----------------
    int type ,node ;
    long long nc ;

    while (Q-- && scanf("%d%d",&type ,&node)){
        if (type==1){
            scanf("%I64d",&nc ) ;
            nc = (1LL<<nc) ;
            set_color(1,0,2*n-1,I[node],O[node],nc) ;
        }
        else{
            long long a = query(1,0,2*n-1,I[node],O[node]) ;
            int ans=0 ;
            for (long long i=(1LL<<60) ;i>1 ;i>>=1 ){
                if (a&i)ans++ ,a^=i;
            }
            printf("%d\n",ans ) ;
        }
    }
}
