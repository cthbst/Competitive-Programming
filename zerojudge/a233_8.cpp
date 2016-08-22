#include<stdio.h>

#define MAXN 1000030

int T[MAXN] ;
void merge_sort(int L ,int R ,int *a ){
	if (L==R)return ;
	int M=(L+R)/2 ;
	merge_sort(L   ,M ,a ) ;
	merge_sort(M+1 ,R ,a ) ;
	int x=L ,l=L ,r=M+1 ;
	while (l<=M && r<=R ){
		if (a[l]<a[r]) T[x++]=a[l++] ;
		else T[x++]=a[r++] ;
	}
	while (l<=M )T[x++]=a[l++] ;
	while (r<=R )T[x++]=a[r++] ;
	for (int i=L ;i<=R ;i++ )a[i]=T[i] ;
}

int N ,a[MAXN] ;

int main(){
	while (~scanf("%d",&N )){
		for (int i=0 ;i<N ;i++ ){
			scanf("%d",a+i) ;
		}
		merge_sort(0 ,N-1 ,a ) ;
		
		for (int i=0 ;i<N ;i++ ){
			printf("%d ",a[i]) ;
		}
		printf("\n") ;
	}
}
