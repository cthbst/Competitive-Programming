#include<stdio.h>
#include<string.h>

#define U 10
int A[1030][3000] ,E=0 ;
int L[1030] ;

int main(){
	memset(A,0,sizeof(A)) ;
	memset(L,0,sizeof(L)) ;
	
	A[0][0]=1 ;
	L[0]=1 ;
	
	for (int i=1 ;i<=1000 ;i++ ){
		int c=0 ;
		L[i]=L[i-1] ;
		for (int j=0 ;j<L[i] ;j++ ){
			c=A[i-1][j]*i+c ;
			A[i][j]=c%U ;
			c/=U ;
		}
		while (c>0){
			A[i][L[i]]=c%U ;
			c/=U ;
			L[i]++ ;
		}
	}
	
	int N ;
	while (~scanf("%d",&N ) ){
		printf("%d!\n",N ) ;
	
		for (int i=L[N]-1 ;i>=0 ;i-- ){
			printf("%d",A[N][i]) ;
		}
		printf("\n") ;
	}
}
