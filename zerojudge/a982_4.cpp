#include<stdio.h>
#include<math.h>

#define MAXAB 7030
int prime[930],sum[MAXAB],len=0 ;

void set_prime(){
	sum[0]=0 ,sum[1]=1 ,sum[2]=1 ;
	prime[len++]=2 ;
	for (int i=3 ;i<=MAXAB ;i++ ){
		bool ok=1 ;
		for (int j=0 ,l=floor(sqrt(i)) ;prime[j]<=l ;j++ )
			if (i%prime[j]==0){
				ok=0 ;
				break ;
			}
		if (ok)prime[len++]=i ;
		
		sum[i]=sum[i-1]+(ok?0:i) ;
	}
}

int main(){
	set_prime() ;
	
	int T ,a ,b ;
	scanf("%d",&T ) ;
	
	while (T-- && scanf("%d%d",&a ,&b )){
		printf("%d\n",sum[b]-sum[a-1] );
	}
	
}
