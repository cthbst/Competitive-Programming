#include<stdio.h>
#include<string.h>
int main(){
	char a[1000] ;
	while (gets(a)){
		int e=2 ,c=0 ;
		for (e=2 ;e<strlen(a) ;e++ ){
			if (a[e]=='(')c++ ;
			else if (a[e]==')')c-- ;
			if (c==0 )break ;
		}
		for (int i=e+2 ;i<strlen(a)-1;i++ )printf("%c",a[i]) ;
		printf(" ") ;
		for (int i=0 ;i<=e ;i++ )printf("%c",a[i]) ;
		printf(";\n") ;
	}
}
