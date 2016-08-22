#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std ;

struct str{int s ,h ;};

const int MaxN =230 ;
int G[MaxN][MaxN] ,dp[MaxN][MaxN] ;

int main(){
    int N ,M ;

    while (~scanf("%d%d",&N ,&M )){
        //input -----------------
        for (int i=1 ;i<=N ;i++ ){
            for (int j=1 ;j<=M ;j++ ){
                scanf("%d",&G[i][j]) ;
            }
        }
        //set_dp ----------------
        for (int j=1 ;j<=M ;j++ ){
            dp[0][j]=0 ;
            for (int i=1 ;i<=N ;i++ ){
                if (G[i][j]==0)dp[i][j]=0 ;
                else dp[i][j]=dp[i-1][j]+1 ;
            }
        }
        //stack count -----------
        int Ans=1 ;

        for (int i=1 ;i<=N ;i++ ){
            for (int j=1 ;j<=M ;j++ ){
                int h=dp[i][j] ;
                for (int k=j+1 ;k<=M ;k++ ){
                    h=min(h,dp[i][k]) ;
                    Ans=max(Ans,h*(k-j+1)) ;
                }
            }
        }
        //output ----------------
        printf("%d\n",Ans ) ;
    }
}
