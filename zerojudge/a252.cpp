#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

const int L =103 ;
char a[L] ,b[L] ,c[L] ;
int dp[L][L][L] ;

int main(){
    scanf("%s%s%s",a+1 ,b+1 ,c+1 ) ;
    memset(dp,0,sizeof(dp)) ;
    int la=strlen(a+1) ,lb=strlen(b+1) ,lc=strlen(c+1) ;
    for (int i=1 ;i<=la ;i++ ){
        for (int j=1 ;j<=lb ;j++ ){
			for (int k=1 ;k<=lc ;k++ ){
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]) ;
				dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]) ;
				dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]) ;
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]) ;
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]) ;
				dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]) ;
                if (a[i]==b[j] && b[j]==c[k] ){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+1) ;
                }
                else {
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]) ;
                }
			}
        }
    }
    printf("%d\n",dp[la][lb][lc]) ;
}
