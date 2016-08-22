#include<stdio.h>
#include<string.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int dp[200] ;

int main(){
    int N ;
    while (~scanf("%d",&N)){
        memset(dp,0,sizeof(dp)) ;
        for (int i=1 ;i<=N ;i++ ){
			for (int j=1 ,ai ;j<=N ;j++ ){
                scanf("%d",&ai ) ;
                dp[j]=max(dp[j],dp[j-1])+ai ;
			}
        }
        printf("%d\n",dp[N]) ;
    }
}
