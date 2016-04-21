#include<bits/stdc++.h>
using namespace std ;

void solve(){
    int n ; scanf("%d",&n ) ;
    int ans= 0 ;
    while (n>0)ans+=n/=5 ;
    printf("%d\n",ans ) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while (T--)solve() ;
}
