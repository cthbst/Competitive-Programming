#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define MAXN 10003
int long long dp[MAXN][11] ;
int in[MAXN] ;

int main(){
    int T ,N ;scanf("%d",&T) ;
    while (T-- && scanf("%d",&N ) ){
          for (int i=1 ;i<=N ;i++ )scanf("%d",&in[i]) ;
          
          //dp-------------------------------------------------------
          memset(dp,2,sizeof(dp)) ; //INF
          
          dp[1][1]=2*in[1] ;          
          for (int i=2 ;i<=N ;i++ )
              for (int j=1 ;j<=7 ;j++ )
                  dp[i][j]=5+in[i]+ min (
                                         min( dp[i-1][j-1]+5 , dp[i-1][j] )+in[i] , 
                                         min( j==5?100000000000000000ll:dp[i-1][j+2]+5 , dp[i-1][j+3] ) 
                                         ) ;
                  
          //output---------------------------------------------------
          printf("%lld\n",dp[N][1]) ;
    }
}
