#include<stdio.h>

int main(){
    int T ;scanf("%d",&T ) ;

    for (int t=1 ,a ,b ;t<=T ;t++ ){
        scanf("%d%d",&a ,&b ) ;
        int l=0 ,r=0 ;
        while (a>1 && b>1){
            if (a>b)
                l+=a/b ,a%=b ;
            else
                r+=b/a ,b%=a ;
        }
        l+=a-1 ,r+=b-1 ;
        printf("Scenario #%d:\n%d %d\n",t ,l ,r) ;
        if (t!=T)printf("\n") ;
    }
}
