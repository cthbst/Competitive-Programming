#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
int N ,K ,L ;
vector<int> pos ;
vector<LL> dp[2] ;

inline int dis(int p){ return min(p,L-p) ; }

void solve(){
    //input -----------------
    scanf("%d%d%d",&N ,&K ,&L ) ;
    pos.resize(N) ,dp[0].resize(N) ,dp[1].resize(N) ;
    for (int i=0 ;i<N ;i++ )scanf("%d",&pos[i]) ;

    //dp --------------------
    for (int i=0 ;i<N ;i++ ){
        dp[0][i]=(LL)( pos[i]+dis(pos[i]) ) ;
        dp[1][i]=(LL)( L-pos[i]+dis(pos[i]) ) ;
    }
    for (int i=K ;i<N ;i++ ){
        dp[0][i]+=dp[0][i-K] ;
    }
    for (int i=N-K-1 ;i>=0 ;i-- ){
        dp[1][i]+=dp[1][i+K] ;
    }

    //solve -----------------
    LL ans = min(dp[0][N-1],dp[1][0]) ;

    for (int i=1 ;i<N ;i++ ){
        ans = min(ans,dp[0][i-1]+dp[1][i]) ;
    }
    printf("%lld\n",ans ) ;
}

int main(){
    //int T ; scanf("%d",&T ) ;
    //while (T--)solve() ;
    solve() ;
}
