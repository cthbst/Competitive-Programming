#include<stdio.h>
#include<algorithm>
using namespace std ;

int main(){
	int T ,n ,in[1010] ;
	scanf("%d",&T ) ;
	while (T-- && scanf("%d",&n)){
		//input----------------------------------
		for (int i=0 ;i<n ;i++ )scanf("%d",&in[i]) ;
		//cooking--------------------------------
		sort(in,in+n) ;
		
		int sum=0 ;
		for (int i=0 ,m=n/2;i<m ;i++ )sum+=in[n-i-1]-in[i] ;
		//output---------------------------------
		printf("%d\n",sum ) ;
	}
}
