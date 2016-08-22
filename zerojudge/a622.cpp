#include<stdio.h>
#include<string.h>

#define N 25
char input[N][132] ,n=0 ;
int lengh[N] ,max_lengh = 0 ;
int main(){
	for ( n ; gets(input[n]) && (strcmp(input[n],"END") != 0) ; n++ ){
		lengh[n]=strlen(input[n]) ;
		if (lengh[n]>max_lengh)max_lengh=lengh[n] ; 
	}
	
	for (int i=0 ;i<max_lengh;i++ ){
		for (int j=0 ;j<n ;j++ ){
			if (i<lengh[j])printf("%c  ",input[j][i]) ;
			else printf("   ") ;
		}
		printf("\n") ;
	}
}
