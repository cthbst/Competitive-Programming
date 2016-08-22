#include<stdio.h>
#include<string.h>
#define MAX 50010
int value[10]={0,5,10,20,50,100,200,500,1000,2000} ;
long long int DP[10][MAX] ;
void set_DP(){
	for (int i=0 ;i<MAX ;i++ )DP[0][i]=1 ;
	for (int i=1 ;i<10;i++ ){
		for (int j=0 ;j<MAX;j++ ){
			DP[i][j]=0 ;
			for (int k=0 ;k<=i && j-value[k]>=0;k++ ){
				DP[i][j]+=DP[k][j-value[k]] ;
			}
		}
	}
}

int main(){
	set_DP() ;
	char input[1000] ;
	while (gets(input)){
		
		int n,SUM=0 ;
		char *pch=strchr(input,' ') ;
		{
			sscanf(input,"%d",&n) ;
			SUM+=n ;
		}
		while (pch){
			sscanf(pch,"%d",&n) ;
			SUM+=n ;
			pch=strchr(pch+1,' ') ; 
		}
		if (!SUM)break ;
		printf("%lld\n",DP[9][SUM]-1) ;
	}
}
