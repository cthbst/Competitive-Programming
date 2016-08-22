#include<stdio.h>
#include<vector>
using namespace std ;

typedef long long int LL ;

int main(){
    int T ,N ,S ;scanf("%d",&T ) ;

    while (T-- && scanf("%d%d",&N ,&S ) ){
        vector<LL> dp(S+1) ;
        dp[0]=1 ;
        for (int i=0 ,d ;i<N ;i++ ){
            scanf("%d",&d ) ;
            for (int i=d ;i<=S ;i++ )dp[i]+=dp[i-d] ;
        }
        printf("%lld\n",dp[S]) ;
    }
}
