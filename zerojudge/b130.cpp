#include<stdio.h>
#include<algorithm>
#define MAX 110 
int f[MAX] ;
int out[MAX] ;int c=1 ;
int main(){
	int n ;
	//input------------------------------------------------
	scanf("%d",&n) ;
	for (int i=0 ;i<n ;i++ )scanf("%d",&f[i]) ;
	//sort-------------------------------------------------
	std::sort(f,f+n) ;
	out[0]=f[0] ;
	for (int i=1 ;i<n ;i++ )if (f[i]!=f[i-1]) out[c++]=f[i] ;
	//output-----------------------------------------------
	printf("%d\n",c ) ;
	for (int i=0 ;i<c ;i++ )printf("%d ",out[i]) ;
}
