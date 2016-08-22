#include<stdio.h>

int main(){
	int n ,out=1 ;
	scanf("%d",&n) ;
	for (int i=0 ;i<=n ;i++ ){
		printf("2^%d = %d\n",i,out) ;
		out*=2 ;
	}
}
