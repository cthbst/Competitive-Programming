#include<stdio.h>
#include<algorithm>
using namespace std ;

typedef long long int LL ;
struct seg{
    LL x ;
    seg *lc ,*rc ;
    seg(LL x=0):x(x){
        lc=rc=nullptr ;
    }
};

void build(seg* &o ,int l ,int r ){
    o=new seg(0) ;
    if (l==r)return ;
    int m=(l+r)>>1 ;
    build(o->lc,l,m) ;
    build(o->rc,m+1,r) ;
}

LL query(seg* &o ,int l ,int r ,int L ,int R ){
    if (L<=l && r<=R )return o->x ;
    if (R<l || r<L )return 0 ;
    int m = (l+r)>>1 ;
    return query(o->lc,l,m,L,R) + query(o->rc,m+1,r,L,R) ;
}

seg* set(seg* &o ,int l ,int r ,int k ,LL v ){
    if (k<l || r<k)return o ;
    if (l==r) return new seg(v) ;

    int m =(l+r)>>1 ;
    seg* re = new seg(0) ;
    re->lc=set(o->lc,l,m,k,v) ;
    re->rc=set(o->rc,m+1,r,k,v) ;
    re->x = re->lc->x + re->rc->x ;

    return re ;
}

seg* his[500000] ;

int main(){
    int N ,T ;
    scanf("%d%d",&N ,&T ) ;

    build(his[0],1,N) ;

    int order ;
    for (int time=1 ;time<=T ;time++ ){
        scanf("%d",&order) ;

        //set a[k]=v ------------------
        if (order==1){
            int k ,v ; scanf("%d%d",&k ,&v ) ;
            his[time]=set(his[time-1],1,N,k,(LL)v) ;
        }
        //query sum(a[l..r]) ----------
        else if (order==2){
            int L ,R ; scanf("%d%d",&L ,&R ) ;
            his[time]=his[time-1] ;
            LL ans = query( his[time],1,N,L,R) ;
            printf("%lld\n",ans) ;
        }
        //to history ------------------
        else if (order==0){
            int k ; scanf("%d",&k ) ;
            his[time]=his[time-1-k] ;
        }
    }
}
