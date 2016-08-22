#include<stdio.h>
#include<math.h>

int P[200] ,len=1 ;

void set_P(){
	P[0]=2 ,len=1 ;
	for (int i=3 ;i<1050 ;i+=2 ){
		bool ok=1 ;
		for (int j=0 ,l=floor(sqrt(i)+0.5);j<len && P[j]<= l ;j++ ){
			if (i%P[j]==0){ ok=0 ;break ; }
		}
		
		if (ok)P[len++]=i ;
	}
} 

int main(){
	set_P() ;
	
	int N ;
	while (~scanf("%d",&N )){
		int i=0 ;
		for (i=0 ;P[i]<=N ;i++ ){
			printf("%10d",P[i]) ;
			if (i%5 ==4 )printf("\n") ;
		}
		if (i%5!=0)printf("\n") ;
	}
}
