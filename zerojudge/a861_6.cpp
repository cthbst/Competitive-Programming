#include<stdio.h>

int main(){
	int T ,N ;
	scanf("%d",&T ) ;
	while (T-- && scanf("%d",&N )){
		double ans=(N+2)*(N+2)/8.0+0.49;
		printf("%d\n",(int)ans) ;
	}
}
