#include<bits/stdc++.h>
using namespace std ;

int n ;
vector< pair<int,int> > seg ;

void solve(){
    scanf("%d",&n ) ;
    seg.resize(n) ;
    for (auto &e:seg)scanf("%d%d",&e.first ,&e.second ) ;
    sort(seg.begin(),seg.end()) ;
    int ans=0 ,left=-1 ;
    for (auto e:seg){
        if (left>=e.second)continue ;
        left=max(left,e.first) ;
        ans+=e.second-left ;
        left=e.second ;
    }
    printf("%d\n",ans ) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while (T--)solve() ;
}
