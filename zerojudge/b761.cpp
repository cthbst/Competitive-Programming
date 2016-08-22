#include<stdio.h>

int main(){
	int n ;
	while (~scanf("%d",&n)){
		puts(n%4==0?"egg":"fat") ;
	}
}
