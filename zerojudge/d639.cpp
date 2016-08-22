#include<stdio.h>
#include<string.h>

typedef long long int LL ;
#define M 10007

void product(LL *A ,LL *B ){
	LL C[3][3] ;
	memset(C,0,sizeof(C)) ;
	
	for (int i=0 ;i<3 ;i++ )
		for (int j=0 ;j<3;j++ )
			for (int k=0 ;k<3;k++ )
				C[i][j]=(C[i][j]+( *(A+3*i+k))*(*(B+k*3+j)) )%M ;
	for (int i=0 ;i<3 ;i++ )
		for (int j=0 ;j<3 ;j++ )
			*(A+3*i+j)=C[i][j] ;
}
void init(LL *A){
	for (int i=0 ;i<3;i++ ){
		for (int j=0 ;j<3 ;j++ ){
			if (i==j)*(A+3*i+j)=1 ;
			else *(A+3*i+j)=0 ;
		}
	}
} 
LL f[33][3][3] ;
void set_f(){
	f[1][0][0]=1 ; f[1][0][1]=1 ; f[1][0][2]=1 ;
	f[1][1][0]=1 ; f[1][1][1]=0 ; f[1][1][2]=0 ;
	f[1][2][0]=0 ; f[1][2][1]=1 ; f[1][2][2]=0 ;
	for (int i=2 ;i<33 ;i++ ){
		init(*f[i]) ;
		product(*f[i],*f[i-1]) ;
		product(*f[i],*f[i-1]) ;
	}
}
int main(){
	set_f() ;
	
	int n ;
	while (~scanf("%d",&n )){
		LL A[3][3] ;
		init(*A) ;
		n-- ;
		for (int i=1 ;n ;i++ ,n/=2 ){
			if (n%2)product(*A,*f[i]) ;
		}
		//output-----------------------
		printf("%lld\n",(A[2][0]+A[2][1]+A[2][2])%M) ;
	}
	
}
