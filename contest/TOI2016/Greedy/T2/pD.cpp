#include<bits/stdc++.h>
using namespace std ;

int n ;
map<int,int> Mx ;

void solve(){
    Mx.clear() ;
    scanf("%d",&n ) ;
    for (int i=0 ,x ,y ;i<n ;i++ ){
        scanf("%d%d",&x ,&y ) ;
        Mx[x] = max(Mx[x],y) ;
        Mx[y] = max(Mx[y],x) ;
    }
    int ans=0 ;
    for (auto e:Mx)ans+=e.second ;
    printf("%d\n",ans ) ;
}

int main(){
    int T ; scanf("%d",&T) ;
    while (T--)solve() ;
}
