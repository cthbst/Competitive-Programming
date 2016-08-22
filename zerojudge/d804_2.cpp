#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define MaxLen 5050

typedef struct {
	int l;
	char first,end ;
}DP_type;

DP_type dp[MaxLen][MaxLen] ;

int main(){
	int T ;
	char input[MaxLen] ;
	scanf("%d",&T ) ;
	while (T-- && scanf("%s",&input )){
		int l=strlen(input) ;
		
		dp[0][l].l=0 ;
		for (int i=0 ;i<l ;i++ ){
			dp[1][i].l=1 ;dp[0][i].l=0 ;
			dp[1][i].first=dp[1][i].end=input[i] ;
		}
		
		for (int i=2 ;i<=l ;i++ ){
			for (int j=0 ,jend=l-i+1 ;j<jend ;j++ ){
				if (dp[i-1][j].first==dp[i-1][j+1].end){
					dp[i][j].l=dp[i-2][j+1].l+2 ;
				}
				else {
					dp[i][j].l=max(dp[i-1][j].l,dp[i-1][j+1].l) ;	
				}
				dp[i][j].first=dp[i-1][j].first ;
				dp[i][j].end=dp[i-1][j+1].end ;
			}
		}
		
		printf("%d\n",dp[l][0].l) ;
	}
}
