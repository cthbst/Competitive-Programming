#include<stdio.h>
#include<string.h>

#define MAX 66
long long int dp[MAX][MAX][2] ;

void set_dp(){
	memset(dp,0,sizeof(dp)) ;
	//s=0----------------------------------------
	dp[0][0][1]= 1 ;
	for (int i=2 ;i<MAX ;i++ ){
		dp[i][0][1]=dp[i-1][0][0]=dp[i-2][0][0]+dp[i-2][0][1] ;
	}
	dp[MAX-1][0][0]=dp[MAX-2][0][0]+dp[MAX-2][0][1] ;
	//s>0----------------------------------------
	for (int i=1 ;i<MAX ;i++ ){
		dp[i][i][1]= 1 ;
		for (int j=i+1 ;j<MAX ;j++ ){
			dp[j][i][1]= dp[j-1][i-1][1] +dp[j-1][i][0] ;
			dp[j][i][0]= dp[j-1][i][1] +dp[j-1][i][0] ;
		}
	}
}

int main(){
	set_dp() ;
	
	int n ,m ;
	while (scanf("%d%d",&n ,&m ) && n>=0 && m>=0 ){
		printf("%lld\n",dp[n][m][0]+dp[n][m][1]) ;
	}
}
