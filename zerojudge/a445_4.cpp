#include<stdio.h>
#define MAX 10010 
int p[MAX] ;

int getfather(int a){
	while (a!=p[a]) a=p[a] ;
	return a ;
}

void add(int a ,int b ){
	if (getfather(a)>getfather(b)){
		p[getfather(a)]=getfather(b) ;
	}
	else {
		p[getfather(b)]=getfather(a) ;
	}
}
int main(){
	int N , M , Q ;
	scanf("%d%d%d",&N ,&M ,&Q ) ;
	for (int i=1 ;i<=N ;i++ )p[i]=i;
	int a ,b ;
	while (M--){
		scanf("%d%d",&a,&b) ;
		add(a,b ) ;
	}
	while (Q--){
		scanf("%d%d",&a,&b) ;
		if (getfather(a)==getfather(b))printf(":)\n") ;
		else printf(":(\n");
	}
}
