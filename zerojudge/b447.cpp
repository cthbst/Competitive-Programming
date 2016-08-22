#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

typedef long long int LL ;
const LL maxN=10000030 ;

int u[maxN] ;
LL U[maxN] ;
void build(){
    static bool p[maxN] ;
    for (int i=0 ;i<maxN ;++i){
        u[i]=1 ,p[i]=1;
    }
    p[0]=p[1]=0 ;
    u[0]=0 ;
    for (LL i=2 ;i<maxN ;++i )if (p[i]){
        LL q=i*i ;
        for (LL j=i ;j<maxN ;j+=i)u[j]=-u[j] ;
        for (LL j=q ;j<maxN ;j+=q)u[j]=0 ;
        for (LL j=q ;j<maxN ;j+=i)p[j]=0 ;
    }
    memset(U,0,sizeof(U)) ;
    for (int i=1 ;i<maxN ;++i ){
        for (int j=1 ;i*j<maxN ;j++ ){
            U[i*j]+=(LL)u[j]*i ;
        }
    }
    for (int i=1 ;i<maxN ;++i){
        U[i]+=U[i-1] ;
    }
}


LL GCDisONE(LL n ,LL m){
    LL ans=0 ;

    LL lastd=0 ,d=1 ;
    LL nm=min(n,m) ,p=n ,q=m ;
    while (d<=nm){
        ans+=p*q*(LL)( U[d]-U[lastd] ) ;
        lastd=d ;
        ++d ;
        // slow -------------
        /*
        p=n/d ;
        q=m/d ;
        continue ;
        */
        //fast --------------
        if (d*p<=n && d*q<=m && p*p<=n && q*q<=m){
            d=nm ;
            d=min(d,(LL)(n/p)) ;
            d=min(d,(LL)(m/q)) ;
        }
        else {
            p=n/d ;
            q=m/d ;
        }
    }
    return ans ;
}

int main(){
    build() ;
    int T ,n ,m ;
    scanf("%d",&T ) ;
    while (T-- && scanf("%d%d",&n ,&m )){
        printf("%lld\n",GCDisONE(n,m)) ;
    }
}
