#include<stdio.h>

int main(){
	int T ,G ,L ; scanf("%d",&T ) ;
	while (T-- && scanf("%d%d",&G ,&L )){
		if (L%G!=0)printf("-1\n") ;
		else printf("%d %d\n",G,L) ;
	}
}
