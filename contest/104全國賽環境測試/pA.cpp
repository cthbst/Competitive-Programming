#include<bits/stdc++.h>
using namespace std ;

typedef long long int LL ;
LL a[100030] ;

int main(){
    int T ; cin >>T ;

    int n ,s ,t ;
    while (T-- && scanf("%d%d%d",&n ,&s ,&t )){
        for (int i=0 ;i<n ;i++ )scanf("%lld",&a[i]) ;
        sort(a,a+n) ;
        LL ans = 0 ;
        for (int i=s-1 ;i<t ;i++ )ans+=a[i] ;
        cout << ans <<endl ;
    }
}
