#pragma GCC optimize ("O3")

#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
const LL INF =(1LL)<<30 ;
const LL MOD = 1000000007LL ;
const int maxn = 2000000 ;
LL X[maxn] ,Y[maxn] ,P[maxn];
int N ,Q ,SEG[maxn] ;

void buildX(int o=1 ,int l=1 ,int r=N){
    if (l>r)return ;
    if (l==r){
        scanf("%lld",&X[o]) ;
        P[o]=X[o] ;
    }
    else {
        int m = (l+r)>>1 ;
        buildX(o<<1,l,m) ;
        buildX(o<<1|1,m+1,r) ;
        X[o]=X[o<<1]*X[o<<1|1] ;
        P[o]=P[o<<1]*P[o<<1|1]%MOD ;
        if (X[o]>INF)X[o]=INF ;
    }
}
LL PRO ,RE ; int XL ,XR ;
void queryX(int o ,int l ,int r ){
    if (XL<=l && r<=XR ){
        PRO=PRO*P[o]%MOD ;
        RE*=X[o] ; if (RE>INF)RE=INF ;
        return ;
    }
    int m =(l+r)>>1 ;
    if (XL<=m)queryX(o<<1,l,m) ;
    if (m< XR)queryX(o<<1|1,m+1,r) ;
}
inline LL queryX(int L ,int R){
    XL=L ,XR=R ,RE=1 ;
    queryX(1,1,N) ;
    return RE ;
}
void updateX(int pos,LL val,int o=1 ,int l=1 ,int r=N){
    if (l==r)X[o]=val ,P[o]=val;
    else {
        int m=(l+r)>>1 ;
        if (pos<=m)updateX(pos,val,o<<1,l,m) ;
        else updateX(pos,val,o<<1|1,m+1,r) ;
        P[o]=P[o<<1]*P[o<<1|1]%MOD ;
        X[o]=X[o<<1]*X[o<<1|1] ;
        if (X[o]>INF)X[o]=INF ;
    }
}
void buildY(int o=1 ,int l=1 ,int r=N){
    if (l==r){
        SEG[o]=l ;
        scanf("%lld",&Y[l]) ;
    }
    else {
        int m = (l+r)>>1 ;
        buildY(o<<1,l,m) ;
        buildY(o<<1|1,m+1,r) ;
        LL a=Y[SEG[o<<1]] ,b=Y[SEG[o<<1|1]]*queryX(SEG[o<<1]+1,SEG[o<<1|1]) ;
        SEG[o]= a>b?SEG[o<<1]:SEG[o<<1|1] ;
    }
}
void updateY(int pos ,LL val ,int o=1 ,int l=1 ,int r=N ){
    if (l==r)Y[l]=val ;
    else {
        int m = (l+r)>>1 ;
        if (pos<=m)updateY(pos,val,o<<1,l,m) ;
        else updateY(pos,val,o<<1|1,m+1,r) ;
        LL a=Y[SEG[o<<1]] ,b=Y[SEG[o<<1|1]]*queryX(SEG[o<<1]+1,SEG[o<<1|1]) ;
        SEG[o]= a>b?SEG[o<<1]:SEG[o<<1|1] ;
    }
}
void solve(){
    //input -----------------
    scanf("%d",&N ) ;
    buildX() ;
    buildY() ;
    PRO=1 ; queryX(1,SEG[1]) ;
    PRO=PRO*Y[SEG[1]]%MOD ;
    printf("%lld\n",PRO ) ;

    //query -----------------
    scanf("%d",&Q ) ;

    for (int i=0 ,t ,u ,v ;i<Q ;i++ ){
        scanf("%d%d%d",&t ,&u ,&v ) ; u++ ;
        if (t==1)updateX(u,(LL)v) ,updateY(u,Y[u]);
        else updateY(u,(LL)v) ;
        PRO=1 ; queryX(1,SEG[1]) ;
        PRO=PRO*Y[SEG[1]]%MOD ;
        printf("%lld\n",PRO ) ;
    }
}

int main(){
    //freopen("C:\\Users\\user\\Desktop\\horses\\tests\\21","r",stdin ) ;
    //freopen("out.txt","w",stdout) ;
    //freopen("pD_in.txt","r",stdin) ;
    solve() ;
}
