#include<stdio.h>

int main(){
	int a ;
	while (scanf("%d",&a)){
		if (a<0){ printf("-1\n") ; break ;}
		printf("%o",a) ;
		printf("\n") ;
	}
}
