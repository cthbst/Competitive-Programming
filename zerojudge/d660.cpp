#include<stdio.h>

#define MAXN 53
int a[53] ;

int main(){
	int T ,N ; scanf("%d",&T ) ;
	
	for (int t=1 ;t<=T ;t++ ){
		scanf("%d",&N) ;
		//input -------------
		for (int i=0 ;i<N ;i++ )scanf("%d",&a[i]) ;
		
		//count -------------
		int H=0 ,L=0 ;
		
		for (int i=1 ;i<N ;i++ ){
			if (a[i]>a[i-1])H++ ;
			else if (a[i]<a[i-1])L++ ;
		}
		
		//output ------------
		printf("Case %d: %d %d\n",t,H,L) ;
		
	}
}
