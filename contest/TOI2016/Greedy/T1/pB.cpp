#include<bits/stdc++.h>
using namespace std ;

int n ;
vector<int> a(n) ;

void solve(){
    scanf("%d",&n ) ;
    a.resize(n) ;
    for (int &e:a)scanf("%d",&e)  ;
    sort(a.begin(),a.end(),greater<int>()) ;
    long long ans=0 ;
    for (int i=0 ;i<n ;i++ ){
        ans += (i*2+1)*a[i] ;
    }
    printf("%lld\n",ans ) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while (T--)solve() ;
}

