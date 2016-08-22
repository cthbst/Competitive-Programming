#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std ;

#define MAX_N 1010 
#define MAX_M 10010 
int N ,M ;

int dp[MAX_N][MAX_M] ;
bool need[MAX_M] ;

int main(){
    while (scanf("%d%d",&N ,&M )){
          if (N==0 && M==0 )break ;
          
          memset(dp,0,sizeof(dp)) ;
          //input------------------------------------------
          for (int i=1 ,in ;i<=N ;i++ ){
              scanf("%d",&in ) ;  
              
              //dp-----------------------------------------
              for (int j=0 ;j<M ;j++ ){
                  if (dp[i-1][j]>0 || j==0 ){
                     dp[i][ (j*10)%M ]=max( dp[i][ (j*10)%M ] , dp[i-1][j] ) ;
                     dp[i][ (j*10+in)%M ]=max( dp[i][ (j*10+in)%M ] , dp[i-1][j]+1 ) ;
                  }
              }
          }
          //find greatest ans------------------------------
          memset(need ,0,sizeof(need)) ;
          for (int i=2 ;i<=M ;i++ ){
              if (M%i==0){
                 for (int j=0 ;j*i<M ;j++ ){
                     need[i*j]=1 ;
                 }
              }
          }
          
          int Ans =0;
          for (int i=0 ;i<M ;i++ ){
              if (need[i]==0 ){
                 for (int j=0 ;j<=N ;j++ ){
                     Ans=max(Ans,dp[j][i]) ;
                 }
              }
          }
          //output-----------------------------------------
          printf("%d\n",Ans ) ;
          
    }
}
