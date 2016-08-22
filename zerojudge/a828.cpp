#include<stdio.h>

int main(){
    int N ;
    while (~scanf("%d",&N )){
        N-- ;
        int len=3+N/81 ;
        int A=1+(N%81)/9 ;
        int B=N%9 ;
        if (B>=A)B++ ;

        char D[3] ;
        if (len&1){
            printf("%d",A ) ;
            D[0]='0'+B ;
            D[1]='0'+A ;
            D[2]=0 ;
        }
        else {
            D[0]='0'+A ;
            D[1]='0'+B ;
            D[2]=0 ;
        }
        for (int i=0 ,l=len/2 ;i<l ;i++ )printf("%s",D ) ;
        printf("\n") ;
    }
}
