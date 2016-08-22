#include<stdio.h>
#include<string.h>
int print_all(int n ,char *A ,int top){
	if (top==n){
		printf("%s\n",A) ;
	}
	else {
		A[top]='0' ;
		print_all(n,A,top+1) ;
		A[top]='1' ;
		print_all(n,A,top+1) ;
	}
}
int main(){
	int n ;
	char A[14] ;
	while (scanf("%d",&n)!=EOF){
		memset(A,0,sizeof(A)) ;
		print_all(n,A,0) ;
	}
}
