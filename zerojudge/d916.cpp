#include<stdio.h>

#define MAXN 3002 
int dp[MAXN] ;

int main(){
	//f(x)=f(x-1)+f(x-1-m)
	int n ,m ;
	while (~scanf("%d%d",&n,&m)){
		int mp=m+1 ;
		for (int i=0 ;i<=m ;i++ )dp[i]=i+1 ;
		for (int i=mp ;i<=n ;i++ ){
			dp[i]=(dp[i-1]+dp[i-mp])%10000 ;
		}
		printf("%d\n",dp[n]%10000) ;
	}
}
