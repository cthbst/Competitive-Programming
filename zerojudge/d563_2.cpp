#include<stdio.h>

const int maxN=100030 ;
int a[maxN] ;

int main(){
	int N ;
	scanf("%d",&N) ;
	for (int i=0 ;i<N ;i++ ){
		scanf("%d",&a[i]) ;
	}
    int suml=0 ,sumr=a[N-1] ;
    int ans=0 ;
    for (int i=0 ,j=N-2 ;0<=j && i<N ;){
        if (suml==sumr){
			ans++ ;
			suml+=a[i++] ;
        }
        else if (suml<sumr){
            suml+=a[i++] ;
        }
        else {
			sumr+=a[j--] ;
        }
    }
    ans++ ;
    printf("%d\n",ans) ;
}
