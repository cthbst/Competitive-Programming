#include<stdio.h>

int GCD(int a,int b){
	if (a==0 )return b ;
	else return GCD(b%a,a) ;
}

int main(){
	int T ;
	scanf("%d",&T ) ;
	
	int a ,b ;
	
	while (T-- && scanf("%d%d",&a ,&b )){
		printf("%d\n",a*b/GCD(a,b)) ;
	}	
}
