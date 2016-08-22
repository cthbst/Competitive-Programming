#include<stdio.h>
#include<string.h>

int main(){
	char s [2030] ;

	int N ;
	scanf("%s",s ) ;
	N = strlen(s) ;

	int i ;
	for (i=0 ;i<N ;i++ ){
		puts(s+i) ;
		s[i+N]=s[i] ;
		s[i+N+1]=0 ;
	}
}
