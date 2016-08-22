#include<bits/stdc++.h>
using namespace std ;

const int maxn = 510 ;
int N ,M ;
int T[maxn][maxn] ;
//1D segment tree -----------
struct seg1D{
    int n ;
    seg1D *lc ,*rc ;
    seg1D(int val=0)
        :n(val),lc(nullptr),rc(nullptr)
        {}
};
void build1D(seg1D* &o,int y ,int l ,int r ){
    o=new seg1D() ;
    if (l==r){
        o->n = T[y][l] ;
    }
    else {
        int m = (l+r)>>1 ;
        build1D(o->lc,y,l,m) ;
        build1D(o->rc,y,m+1,r) ;
        o->n=max(o->lc->n,o->rc->n) ;
    }
}
void Merge(seg1D* &o ,seg1D* &L ,seg1D* &R ,int l ,int r){
    o = new seg1D( max(L->n,R->n) ) ;
    if (l==r)return ;
    int m=(l+r)>>1 ;
    Merge(o->lc,L->lc,R->lc,l,m) ;
    Merge(o->rc,L->rc,R->rc,m+1,r) ;
}
int query1D(seg1D* o,int l ,int r ,int L,int R){
    if (R<l || r<L )return -1 ;
    if (L<=l && r<=R )return o->n ;
    int m = (l+r)>>1 ;
    return max( query1D(o->lc,l,m,L,R) ,
                query1D(o->rc,m+1,r,L,R)
              ) ;
}
//2D segment tree -----------
struct seg2D{
    seg1D *S ;
    seg2D *lc ,*rc ;
    seg2D(int val=0)
        :S(nullptr),lc(nullptr),rc(nullptr)
        {}
};
void build2D(seg2D* &o ,int l,int r){
    o=new seg2D() ;
    if (l==r){
        build1D(o->S,l,1,M) ;
    }
    else {
        int m = (l+r)>>1 ;
        build2D(o->lc,l,m) ;
        build2D(o->rc,m+1,r) ;
        Merge(o->S,o->lc->S,o->rc->S,1,M) ;
    }
}
int qy ,qY ,qx ,qX ;
int query2D(seg2D*&o ,int l=1,int r=N){
    if (r<qy || qY<l)return 0 ;
    if (qy<=l && r<=qY ){
        return query1D(o->S,1,M,qx,qX) ;
    }
    else {
        int m = (l+r)>>1 ;
        return max (    query2D(o->lc,l,m),
                        query2D(o->rc,m+1,r)
                    ) ;
    }
}

seg2D *Seg =nullptr ;

int main(){
    scanf("%d%d",&N ,&M ) ;
    for (int i=1 ;i<=N ;i++ ){
        for (int j=1 ;j<=M ;j++ ){
            scanf("%d",&T[i][j]) ;
        }
    }
    build2D(Seg,1,N) ;

    //query -----------------
    int Q ; scanf("%d",&Q ) ;

    for (int i=0 ;i<Q ;i++ ){
        scanf("%d%d%d%d",&qy ,&qx ,&qY ,&qX ) ;
        printf("%d\n",query2D(Seg) ) ;
    }
}
