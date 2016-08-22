#include<stdio.h>
#include<string.h>

int main(){
	int T ; scanf("%d",&T ) ;
	int N ;
	while (T-- && scanf("%d",&N ) ){
		if (N==0){
			printf("0\n") ;
			continue ;
		}
		if (N==1){
			printf("1\n") ;
			continue ;
		}
		int count[10] ;
		memset(count,0,sizeof(count)) ;
		for (int i=9 ;i>=2 ;i-- ){
			while (N%i==0){
				count[i]++ ;
				N/=i ;
			}
		}
		
		if (N>1){
			printf("-1\n") ;
			continue ;
		}
		for (int i=2 ;i<=9 ;i++ ){
			while (count[i]>0){
				printf("%d",i) ;
				count[i]-- ;
			}
		}
		printf("\n") ;
	}
}
