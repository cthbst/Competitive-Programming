#include<bits/stdc++.h>
using namespace std ;

long long Abs (long long x){
    if (x>0)return x ;
    return -x ;
}

int main(){
    int n ; cin >> n ;

    long long ans = 0 ,last=0 ,ai ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%I64d",&ai ) ;
        ans += Abs(ai-last) ;
        last= ai ;
    }
    cout << ans <<endl ;
}
