#include<stdio.h>

int GCD(int a ,int b ){
    if (b)return GCD(b,a%b) ;
    return a ;
}

int main(){
    int N ,Ans ;
    while (~scanf("%d",&N ) ){
        scanf("%d",&Ans ) ;
        for (int i=1 ,in ;i<N ;i++ ){
            scanf("%d",&in ) ;
            Ans=GCD(Ans ,in ) ;
        }
        printf("%d\n",Ans ) ;
    }
}
