#include<stdio.h>
#include<algorithm>
using namespace std ;

#define MAX 30010
long long int dp[MAX] ;

void set_dp(){
	fill(dp,dp+MAX,1) ;
	int type=5 ;
	int coin[]={ 1,5,10,25,50 } ;
	
	for (int i=1 ;i<type ;i++ ){
		int t=coin[i] ;
		for (int j=t ;j<MAX ;j++ ){
			dp[j]+=dp[j-t] ;
		}
	}
}

int main(){
	set_dp() ;
	
	int n ;
	while (~scanf("%d",&n)){
		long long int ans=dp[n] ;
		if (ans==1){
			printf("There is only 1 way to produce %d cents change.",n) ; 
		}
		else {
			printf("There are %lld ways to produce %d cents change.",ans,n) ;
		}
		printf("\n") ;
	}
}
