#include<stdio.h>
#define Max 100010 
long long int in[Max] ,S[Max] ;

int main(){
	int n ,m ,a ,b ;
	while (~scanf("%d%d",&n ,&m )){
		S[0]=0 ;
		for (int i=1 ;i<=n ;i++ ){
			scanf("%lld",in+i) ;
			S[i]=S[i-1]+in[i] ;
		}
		while (m--){
			scanf("%d%d",&a ,&b ) ;
			printf("%lld\n",S[b]-S[a-1]) ;
		}		
	}
}
