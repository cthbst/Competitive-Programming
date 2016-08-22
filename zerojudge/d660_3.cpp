#include<stdio.h>
#include<math.h>

int main(){
	int T ,N ,P ,A ,B ; scanf("%d",&T ) ;
	
	while (T-- && scanf("%d%d",&N ,&P ) ){
		A=(int)ceil( ((N+1)/2) *P +( N /2) *P *0.6 ) ;
        B=(int)ceil( N *P *0.812 );
		if (A>B)printf("8-12=-4") ;
		else if (A<B)printf(": )") ;
		else printf("SAME") ;
		printf("\n") ;
	}
}
