#include<stdio.h>
#include<algorithm>
using namespace std ;

int main(){
    int T ;scanf("%d",&T ) ;

    for (int i=1 ;i<=T ;i++ ){
        int sum ,a ,b ,c ;
        scanf("%d%d%d",&a ,&b ,&c ) ;
        sum=a+b+c ;
        sum-=max(a,max(b,c)) ;
        sum-=min(a,min(b,c)) ;
        printf("Case %d: %d\n",i ,sum ) ;
    }
}
