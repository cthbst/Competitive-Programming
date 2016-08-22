#include<stdio.h>

int main(){
	int L ,W ,x ,y ;
	while (scanf("%d%d%d%d",&L ,&W ,&x ,&y ) && L!=0 && W!=0 && x!=0 && y!=0 ){
		if ( (L%x==0 && W%y==0 ) || (L%y==0 && W%x==0 ) )printf("%d\n",L*W/x/y) ;
		else printf("-1\n") ;
	}
}
