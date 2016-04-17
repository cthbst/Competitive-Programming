#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100 ;
int n ;
map<int,int> cnt ;

void solve(){
    cnt.clear() ;
    scanf("%d",&n ) ;
    for (int i=n*(2*n-1)-1 ,ai ;i>=0 ;i-- ){
        scanf("%d",&ai ) ;
        cnt[ai]++ ;
    }
    for (auto e:cnt){
        if (e.second%2==1)printf(" %d",e.first ) ;
    }
    puts("") ;
}

int main(){
    freopen("B-large.in","r",stdin) ;
    freopen("B-large_out.txt","w",stdout ) ;
    int T ; scanf("%d",&T ) ;
    for (int i=1 ;i<=T ;i++ ){
        printf("Case #%d:",i) ;
        solve() ;
    }
}

