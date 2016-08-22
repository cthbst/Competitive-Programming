#include<stdio.h>
#define MAXN 10010
long long int duck[MAXN] ;
long long int f(long long int a ,long long int b){
	while (1){
		if (a==0)return b ;
		b%=a ;
		if (b==0)return a ;
		a%=b ;		
	}
}
long long int abs(long long int a){
	return a>0 ?a:-a  ;
}
int main(){
	/*
	freopen("2.txt","r",stdin) ;
	freopen("2.out","w",stdout) ;
	*/
	int T ;
	scanf("%d",&T ) ;
	while (T--){
		//input--------------------------------------------
		int N ;
		scanf("%d",&N) ;
		scanf("%lld",&duck[0]) ;
		for (int i=1 ;i<N;i++ ){
			scanf("%lld",&duck[i]) ;
			duck[i-1]=abs(duck[i]-duck[i-1]) ;
		}
		//cooking------------------------------------------
		long long ans=duck[0] ;
		for (int i=1 ;ans>1 && i<N-1;i++ )ans=f(ans,duck[i]) ;
		//output-------------------------------------------
		printf("%lld\n",ans) ;
	}
	return 0 ;
}
