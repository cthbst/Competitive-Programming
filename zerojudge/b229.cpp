#include<stdio.h>

#define MAXN 50 
unsigned long long int U[MAXN],L[MAXN] ;
int main(){
	U[0]=L[0]=1 ;
	for (int i=1 ;i<MAXN ;i++ ){
		U[i]=U[i-1]+2*L[i-1] ;
		L[i]=U[i-1]+L[i-1] ;
	}
	char U50[]="16616132878186749607" ;
	int n; 
	while (~scanf("%d",&n)){
		if (n<50)printf("%lld\n",U[n]) ;
		else printf("%s\n",U50) ;
	}
}
