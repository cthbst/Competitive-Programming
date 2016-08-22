#include<stdio.h>
#include<string.h>

int main(){
	char name[100] ;
	double B ,V ;
	while (scanf("%s%lf%lf",&name ,&B ,&V ) && strcmp(name,"END")!=0 ){
		printf("%s %.2lf ",name ,B-V ) ;
		
		double d=B-V ;
		if      (d < -0.25)printf("O") ;
		else if (d <  0.0 )printf("B") ;
		else if (d <  0.25)printf("A") ;
		else if (d <  0.5 )printf("F") ;
		else if (d <  1.0 )printf("G") ;
		else if (d <  1.5 )printf("K") ;
		else printf("M") ;
		
		printf("\n") ;
	}
}
