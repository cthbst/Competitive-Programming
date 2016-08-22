#include<stdio.h>

int main(){
	int T ; scanf("%d",&T ) ;
	
	int x1 ,x2 ,x3 ,y1 ,y2 ,y3 ;
	while (T-- ){
		scanf("%d%d%d%d%d%d",&x1 ,&y1 ,&x2 ,&y2 ,&x3 ,&y3 ) ;
		if ( (x1-x2)*(y2-y3)==(x2-x3)*(y1-y2))printf("NO\n") ;
		else printf("YES\n") ;
	}
}
