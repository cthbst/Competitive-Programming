#include<stdio.h>
#include<deque>
#include<algorithm>
using namespace std ;

typedef long long int LL ;
const LL INF = (1LL << 62) ;
deque< pair<LL,int> > duck[2] ;
#define val first
#define index second

int main(){
    int n ,delta ;
    scanf("%d%d",&n ,&delta ) ;

    LL ans ,ai ;

    scanf("%lld",&ai) ;
    ans=ai ;
    duck[0].push_back( make_pair(ai,0) ) ;
    duck[1].push_back( make_pair(-INF,0) ) ;

    LL dp[2] ;
    for (int i=1 ;i<n ;i++ ){
        scanf("%lld",&ai) ;

        if (duck[0].front().index<i-delta) duck[0].pop_front() ;
        if (duck[1].front().index<i-delta) duck[1].pop_front() ;

        dp[0] = max(ai, duck[1].front().val+ai ) ;
        dp[1] = duck[0].front().val-ai ;
        ans=max(ans, max(dp[0],dp[1]) ) ;

        while (!duck[0].empty()  && duck[0].back().val<=dp[0])
            duck[0].pop_back() ;
        while (!duck[1].empty()  && duck[1].back().val<=dp[1])
            duck[1].pop_back() ;
        duck[0].push_back( make_pair(dp[0],i) ) ;
        duck[1].push_back( make_pair(dp[1],i) ) ;
    }
    printf("%lld\n",ans) ;
}
