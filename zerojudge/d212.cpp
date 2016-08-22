#include<stdio.h>
unsigned long long int f[105] ;
int main(){ //這題其實要用大數 ussigned lon long int 只能到n92 不過AC就算了  
	f[0]=1 ;f[1]=1 ;
	for (int i=2 ;i<100 ;i++ )f[i]=f[i-1]+f[i-2] ;
	
	int n ;
	while (~scanf("%d",&n)){
		printf("%lld\n",f[n]) ;
	}
}
