#include<stdio.h>
#include<string.h>

int main(){
	int T ;
	scanf("%d",&T ) ;
	
	char in[10000] ;
	while (T-- && scanf("%s",&in )){
		int sum1=0 ,sum2=0 ,l=strlen(in) ;
		
		for (int i=l-1 ;i>=0 ;i-=2 )sum1+=in[i]-'0' ;
		for (int i=l-2 ;i>=0 ;i-=2 )sum2+=in[i]-'0' ;
		
		if ((sum1+2*sum2)%3==0 || (2*sum1+sum2)%3==0 ){
			printf("Yes\n") ;
		}
		else {
			printf("No\n") ;
		}
 	}
}
