#include<stdio.h>
#include<math.h>

int main(){
	int N ,M ;
	
	while (~scanf("%d%d",&N ,&M )){
		double lg=log(N)/log(10) ;
		lg*=M ;
		printf("%d\n",(int)floor(lg)+1) ;	
	}
	
}
