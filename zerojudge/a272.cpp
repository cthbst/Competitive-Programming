#include<stdio.h>
#include<string.h>

#define M 10007

void product(int *a ,int *b){
	int c[2][2] ;
	memset(c,0,sizeof(c)) ;
	
	for (int i=0 ;i<2;i++ )
		for (int j=0 ;j<2;j++ )
			for (int k=0 ;k<2;k++ )
				c[i][j]=(c[i][j]+(*(a+2*i+k))*(*(b+2*k+j)))%M ;
	
	for (int i=0 ;i<2;i++ )
		for (int j=0 ;j<2;j++ )
			*(a+2*i+j)=c[i][j] ;
}

int f[33][2][2] ;
void set_f(){
	f[1][0][0]=f[1][0][1]=f[1][1][0]=1 ;f[1][1][1]=0 ;
	for (int i=2 ;i<33;i++ ){
		f[i][0][1]=f[i][1][0]=0 ;f[i][0][0]=f[i][1][1]=1 ;
		product(*f[i],*f[i-1]) ;
		product(*f[i],*f[i-1]) ;
	}
}
int main(){
	set_f() ;
	
	long long int n ;
	while (~scanf("%lld",&n )){
		int A[2][2] ;
		A[0][0]=A[1][1]=1 ;A[0][1]=A[1][0]=0 ;
		//cooking--------------------------------
		n++ ;
		for (int i=1 ;n;i++ ,n/=2)if (n%2){
			product(*A,*f[i]) ;
		} 
		//output---------------------------------
		printf("%d\n",A[0][1]) ;
	}
}
