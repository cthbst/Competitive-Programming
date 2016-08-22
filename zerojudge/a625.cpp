#include<stdio.h>

int main(){
	double C ;
		
	while (~scanf("%lf",&C )){
		int N =0 ;
		while (C>0.0){
			C-=1.0/((double)(N+2)) ;
			N++ ;
		}
		
		printf("%d card(s)\n",N ) ;
	}
}
