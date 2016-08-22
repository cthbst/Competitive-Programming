#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define MAXM 26
int v[MAXM] ,p[MAXM] ;
#define MAXN 30001
long long int dp[MAXN] ;

int main(){
	int N ,m ;
	while (~scanf("%d%d",&N ,&m )){
		for (int i=0 ;i<m ;i++ )scanf("%d%d",&v[i] ,&p[i] ) ;
		
		//DP-----------------------------------------------
		memset(dp,0,sizeof(dp)) ;
		for (int i=0 ;i<m ;i++ ){
			for (int j=N ;j>=v[i] ;j-- ){
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]) ;
			}
		}
		//output-------------------------------------------
		printf("%lld",dp[N]) ;
	}
}
