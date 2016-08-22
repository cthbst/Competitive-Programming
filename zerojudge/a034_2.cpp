#include<stdio.h>
#include<string.h>

#define MAX 1000010 
char input[MAX][110] ;
int S[MAX] ;

int BSA(int l ,int r ,int t ){
	int m=(l+r)/2 ;
	if (S[m]==t)return m ;
	if (S[m]>t && S[m+1]>t )return BSA(l,m,t) ;
	if (S[m]<t && S[m+1]<=t )return BSA(m+1,r,t) ;
	else return m ;
}

int main(){
	int  n, m ;
	while (scanf("%d%d",&n ,&m )){
		if (n==0 && m==0 )break ;
		
		//input input------------------------------------------------
		S[0]=1 ;
		for (int i=0 ;i<n ;i++ ){
			scanf("%s",input[i]) ;
			S[i+1]=S[i]+strlen(input[i]) ;
		}
		//input array------------------------------------------------
		int aph ;
		for (int i=0 ;i<m ;i++ ){
			scanf("%d",&aph ) ;
			
			int f=BSA(0,n-1,aph) ;
			printf("%c",input[f][aph-S[f]]) ;
		}
		
		printf("\n") ;
	}	
}
