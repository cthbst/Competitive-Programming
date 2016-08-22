#include<stdio.h>

int main(){
	long long int f[9] ,pf[9] ;
	pf[0]=1 ;
	f[0]=2 ;f[1]=3 ;
	for (int i=2 ;i<9 ;i++ )f[i]=f[i-1]+f[i-2] ;
	for (int i=1 ;i<9 ;i++ )pf[i]=pf[i-1]*f[i-1] ;
	
	int n ;
	while (~scanf("%d",&n)){
		int i=8 ;
		for (i;i>=0 ;i-- )if (pf[i]<=n)break ;
		for (i;i>0 ;i-- ){
			printf("%d,",n/pf[i]) ;
			n%=pf[i] ;
		}
		printf("%d\n",n) ;
	}
}
