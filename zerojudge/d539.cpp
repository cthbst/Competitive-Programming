#include<stdio.h>
#include<algorithm>
using namespace std ;

const int maxN= 500000 ;

int seg[maxN*4] ;

void build(int o ,int l ,int r ){
    if (l==r)scanf("%d",&seg[o]) ;
    else {
        int m=(l+r)>>1 ,lc=o*2 ,rc=o*2+1 ;
        build(lc,l,m) ;
        build(rc,m+1,r) ;
        seg[o]=max(seg[lc],seg[rc]) ;
    }
}

const int INF = 1<<30 ;

int query(int o ,int l ,int r ,int L ,int R ){
    if (L<=l && r<=R)return seg[o] ;
    if (R<l || r<L )return -INF ;
    int m=(l+r)>>1 ,lc=o*2 ,rc=o*2+1 ;
    return max( query(lc,l,m,L,R) , query(rc,m+1,r,L,R) ) ;
}

int main(){
    int N ;
    scanf("%d",&N ) ;
    build (1,1,N) ;
    int Q ,l ,r ;
    scanf("%d",&Q ) ;
    while (Q-- && scanf("%d%d",&l ,&r )){
        printf("%d\n",query(1,1,N,min(l,r),max(l,r))) ;
    }
}
