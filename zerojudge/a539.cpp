#include<stdio.h>

int Ans ;

void  marge_sort(int *a ,int left ,int right ,int *T ){
	if (left == right )return ;
	int mid=(left+right)/2 ;
	
	marge_sort(a,left  ,mid   ,T) ;
	marge_sort(a,mid+1 ,right ,T) ;
	
	int x=left ,lc=left ,rc=mid+1 ;
	
	while (lc<=mid && rc<=right ){
		if (a[lc] <=a[rc] ){
			T[x++]=a[lc++] ;
		}
		else {
			Ans+=mid-lc+1 ;
			T[x++]=a[rc++] ;
		}
	}
	while (lc<=mid)  T[x++]=a[lc++] ;
	while (rc<=right)T[x++]=a[rc++] ;
	
	for (int i=left ;i<=right ;i++ )a[i]=T[i] ;
}

int a[1030] ,T[1030];

int main(){
	int N ;
	while (~scanf("%d",&N ) ){
		for (int i=0 ;i<N ;i++ )scanf("%d",&a[i]) ;
		Ans=0 ;
		marge_sort(a,0,N-1,T) ;
		printf("Minimum exchange operations : %d\n",Ans ) ;
	}
}
