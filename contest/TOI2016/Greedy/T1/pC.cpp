#include<bits/stdc++.h>
using namespace std ;

int n ;
vector< pair<int,int> > a ;

void solve(){
    scanf("%d",&n ) ;
    a.resize(n) ;
    for (auto &e:a)scanf("%d",&e.second ) ;
    for (auto &e:a)scanf("%d",&e.first ) ;
    sort(a.begin(),a.end()) ;
    int sum=0 ,ok=1 ;
    for (auto e:a){
        sum+=e.second ;
        if (sum>e.first){
            ok=0 ;
            break ;
        }
    }

    puts(ok?"Yes":"No") ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while (T--)solve() ;
}
