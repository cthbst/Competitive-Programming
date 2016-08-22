#include<stdio.h>
#define MAXN 100010 
int a[MAXN] ;
int N ,k ;

int find(int n ,int l ,int r){
	if (a[l]>n || a[r-1]<n )return 0 ;
	if (r-l==1){
		if (a[l]==n)return l+1 ;
		return 0 ;
	}
	int m = (l+r)/2  ;
	return find(n,l,m)+find(n,m,r) ;
}

int main(){
	//input----------------------------------------------------------
	scanf("%d%d",&N,&k ) ;
	for (int i=0 ;i<N ;i++ )scanf("%d",&a[i]) ;
	//finding--------------------------------------------------------
	int n ;
	while (k--){
		scanf("%d",&n) ;
		printf("%d\n",find(n,0,N)) ;
	}
}
