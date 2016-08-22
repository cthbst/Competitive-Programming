#include<stdio.h>

#define MAXN 100030
int a[MAXN] ,F ;

int BSA(int l ,int r){
	if (l==r )return l ;
	int mid=(l+r)/2 ;
	if (a[mid]==F )return mid ;
	if (a[mid]<F)return BSA(mid+1 ,r ) ;
	return BSA(l ,mid) ; 
}

int main(){
	int N ,K ;
	a[0]=0 ;
	scanf("%d%d",&N ,&K ) ;
	//input--------------------------------------
	for (int i=1 ;i<=N ;i++ )
		scanf("%d",&a[i]) ;
	//BSA----------------------------------------
	while (K-- && scanf("%d",&F )){
		int l=BSA(1,N) ;
		if (a[l]!=F)printf("0\n") ;
		else printf("%d\n",l) ;
	}
}
