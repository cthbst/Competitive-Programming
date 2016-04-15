#include<bits/stdc++.h>
using namespace std ;

int n ,m ;
priority_queue<int,vector<int>,greater<int> > que ;
void solve(){
    while (!que.empty())que.pop() ;
    scanf("%d%d",&n ,&m ) ;
    for (int i=0 ;i<m ;i++ )que.push(0) ;
    long long ans=0 ;
    for (int i=0 ,ai ;i<n ;i++ ){
        scanf("%d",&ai ) ;
        ai+=que.top() ; que.pop() ;
        que.push(ai) ;
        ans=max(ans,ai) ;
    }
    printf("%lld\n",ans ) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while(T--)solve() ;
}
