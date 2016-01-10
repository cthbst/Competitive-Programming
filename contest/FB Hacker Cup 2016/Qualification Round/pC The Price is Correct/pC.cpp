#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;

const int maxn = 100000 ;
int n ,P ,a[maxn] ,sum=0 ;

LL solve(){
    scanf("%d%d",&n ,&P ) ;
    for (int i=0 ;i<n ;i++ )scanf("%d",&a[i]) ;

    LL re=0 ,sum=0 ;
    for (int l=0 ,r=0 ;r<n ; ){ //[l,r)
        sum+=a[r++] ;
        while (sum>P)sum-=a[l++];
        re+=(LL)(r-l) ;
    }
    return re ;
}

int main(){
    freopen("the_price_is_correct.txt","r",stdin) ;
    freopen("pC_out.txt","w",stdout) ;
    int T ; cin >> T ;

    for (int t=1 ;t<=T ;t++ ){
        printf("Case #%d: %lld\n",t ,solve()) ;
    }
}
