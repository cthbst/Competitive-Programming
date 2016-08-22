#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define N 1010
int a[N] ;

int main(){
	int T ,n ;
	scanf("%d",&T ) ;
	
	while (T-- && scanf("%d",&n)){
		//input--------------------------------------------
		for (int i=0 ;i<n ;i++ ){
			scanf("%d",&a[i]) ;
		}
		//walk---------------------------------------------
		int ans=a[0] ,sum=0 ;
		for (int i=0 ;i<n ;i++ ){
			if (sum>0 )
				sum+=a[i] ;
			else 
				sum=a[i] ;
			
			ans=max(ans,sum) ;
		}
		printf("%d\n",ans) ;
	}
}
