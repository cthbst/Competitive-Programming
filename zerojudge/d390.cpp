#include<stdio.h>
#include<string.h>
#define MAXM 105 
int coin[MAXM] ;
bool dp[MAXM*500] ;
int main(){
	int T ;
	scanf("%d",&T ) ;
	while (T--){
		memset(dp,0,sizeof(dp)) ;
		int m ,SUM=0 ;
		//input------------------------------------------------------
		scanf("%d",&m) ;
		for (int i=0 ;i<m ;i++ ){
			scanf("%d",&coin[i]) ;
			SUM+=coin[i] ;
		}
		//dp---------------------------------------------------------
		for (int i=0 ;i<m ;i++ ){
			for (int j=SUM ;j>=0 ;j-- ){
				if (dp[j]==1 )dp[ j+coin[i] ]=1 ;
			}
			dp[ coin[i] ]=1 ;
		}
		//output-----------------------------------------------------
		for (int i=SUM/2 ;i>0 ;i-- )if (dp[i]){
			printf("%d\n",SUM-i*2) ;
			break ;
		}
	} 
}
