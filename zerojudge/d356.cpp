#include<stdio.h>

const double EPS = 1E-8 ;

int main(){
    int a[20] ;

    double sum=0.0 ;
    for (int i=1 ,j=1 ;i<=15 ;i++ ){
        while (sum-EPS<(double)i){
            sum+=1.0/(double)j ;
            j++ ;
        }
        a[i]=j-1 ;
    }
    int K ;
    while (~scanf("%d",&K)){
        printf("%d\n",a[K]) ;
    }
}
