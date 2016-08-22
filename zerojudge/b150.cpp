#include<stdio.h>

int main(){
	int a[13] ;
	
	while (~scanf("%d",&a[1]) ){
		for (int i=2 ;i<=12 ;i++ )scanf("%d",&a[i]) ;
		
		int sum=0 ,H=0 ,ok=1 ;
		
		for (int i=1 ;i<=12 ;i++ ){
			sum+=300-a[i] ;
			if (sum<0){
				printf("-%d",i) ;
				ok=0 ;
				break ;
			}
			H+=sum/100 ;
			sum%=100 ;
		}
		if (ok)printf("%d\n",sum+H*120) ;
	}
}
