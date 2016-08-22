#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define MAXN 10010
#define MAXB 110
int dp[MAXN][MAXB] ;

int main(){
    int N ;
    while (~scanf("%d",&N )){
          memset(dp,0,sizeof(dp)) ;
          int a,b ;
          for (int i=1 ;i<=N ;i++ ){
              scanf("%d%d",&a ,&b ) ;
              for (int j=0 ;j<=100 ;j++ ){
                  if (j>=a)dp[i][j]=max(dp[i-1][j],dp[i-1][j-a]+b) ;
                  else dp[i][j]=dp[i-1][j] ;
              }       
          }
          printf("%d\n",dp[N][100]) ;
    }    
}
