#include<stdio.h>
#include<algorithm>
using namespace std ;

#define MAXN 751
long long int dp[MAXN] ;

int main(){
	fill(dp,dp+MAXN,1) ; 
	for (int i=3 ;i<MAXN;i+=2 ){
		for (int j=i ;j<MAXN ;j++ ){
			dp[j]+=dp[j-i] ;
		}
	}
	int T ,N ;
	scanf("%d",&T );
	while (T--){
		scanf("%d",&N ) ;
		printf("%lld\n",dp[N]) ;
	}
}
