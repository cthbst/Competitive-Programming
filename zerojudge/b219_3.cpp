#include<stdio.h>
long long dp[3];
int main(){
	long long int n ,m ;
	while (~scanf("%lld%lld",&n,&m)){
		dp[1]=1 ;dp[2]=1;
		for (long long int i=3 ;i<=n ;i++ )
			dp[i%3]=(dp[(i-1)%3]*(i-1)+dp[(i-2)%3]*(i-2))%m ;
		printf("%d\n",dp[(n)%3]) ;
	}	
}
