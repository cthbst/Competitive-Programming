#include<stdio.h>
#include<math.h>
int main(){
	int in0 ;
	scanf("%d",&in0) ;
	while (in0--){
		int H ,count=1 ;
		scanf("%d",&H) ;
		while (1){
			if((int)pow(2,count+1)-1>H) break ;
			count++ ;
		}
		H-=(int)pow(2,count)-1 ;
		while (H){
			count+=H%2 ;
			H/=2 ;
		}
		printf("%d\n",count) ;
	}
}
