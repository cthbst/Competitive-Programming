#include<bits/stdc++.h>
using namespace std ;

void print_binary(long long x ){
    long long i = (1LL)<<32 ;
    while ((x&i)==0)i>>=1 ;
    while (i>0){
        if ((x&i)>0)printf("1") ;
        else printf("0") ;
        i>>=1 ;
    }
}
long long trans_base(long long x,int base){
    long long re=0 ,d=1 ;
    while (x>0){
        if (x&1)re+=d ;
        d*=base ;
        x>>=1 ;
    }
    return re ;
}

void solve(){
    int N ,J ;
    cin >> N >> J ;
    long long factor = 1 + ((1LL)<<(N>>1)) ;
    //print_binary(factor) ;puts("") ;
    long long d = 1 + (factor>>1) ;
    for (int i=0 ;i<J ;i++ ){
        int n = d+i ;
        print_binary(factor*(d+i*2)) ;
        for (int j=2 ;j<=10 ;j++ ){
            printf(" %lld",trans_base(factor,j)) ;
        }
        puts("") ;
    }
}

int main(){
    freopen("C-small-attempt0.in","r",stdin) ;
    freopen("out.txt","w",stdout) ;
    int T ; scanf("%d",&T ) ;
    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d:\n",t ) ;
        solve() ;
    }
}
