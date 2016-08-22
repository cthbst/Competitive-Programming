#include<stdio.h>

int main(){
	int m ,n ;
	while (scanf("%d%d",&m,&n) && (m+n)!=0 ){
		int count =0 ,add=0;
		while (1){
			if (m*n==0 && m%10+n%10+add<10)	break ;			
			if (m%10+n%10+add>9){ add=1 ; count++ ; }
			else add=0 ;
			m/=10 ;n/=10 ;
		}
		if (count==0 ) printf("No carry operation.\n") ;
		else if (count==1 ) printf("1 carry operation.\n") ;
		else printf("%d carry operations.\n",count) ;
	}
}
