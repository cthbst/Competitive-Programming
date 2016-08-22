#include<stdio.h>

#define MAX 1026 
int a[MAX] ;

int main(){
	int T ,n ;
	scanf("%d",&T );
	while (T-- && scanf("%d",&n)){
		//input--------------------------------------------
		for (int i=0 ;i<n ;i++ ){
			scanf("%d",&a[i]) ;
		}
		//walk---------------------------------------------
		int ans=a[0] ,sum=0 ;
		for (int i=0 ;i<n ;i++ ){
			if (sum>0 ){
				sum+=a[i] ;
			}
			else {
				sum=a[i] ;
			}
			
			if (sum>ans)ans=sum ;
		}
		//output-------------------------------------------
		printf("%d\n",ans) ;
	}
	
}
