#include<stdio.h>
#include<math.h>
int main(){
	int N ,M ,L ;
	while (~scanf("%d",&N) ){
		M=sqrt(N) ;
		L=N-M*M ;
		
		for (int i=1 ;i<M ;i++ ){
			printf("%d ",i) ;
			if (i==L%M)printf("%d ",i) ;
		}
		
		for (int i=0 ;i<=L/M ;i++ ){
			printf("%d ",M) ;
		}
		
		for (int i=M-1 ;i>0 ;i--){  
			printf("%d ",i) ;
		}
		printf("\n") ;
	}
}
