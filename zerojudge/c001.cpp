#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 1005
char A[MAX],B[MAX];
int dp[MAX][MAX] ;
int main(){
    while (~scanf("%s%s",&A,&B )){
          memset(dp,0,sizeof(dp) ) ;
          int a=strlen(A) ,b=strlen(B) ;
          
          for (int i=1 ;i<=a;i++ ){
              for (int j=1 ;j<=b ;j++ ){
                  if (A[i-1]==B[j-1])dp[i][j]=dp[i-1][j-1]+1 ;
                  else dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ;
              }
          }
          printf("%d\n",dp[a][b]) ;
    }
}
