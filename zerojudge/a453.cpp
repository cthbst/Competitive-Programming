#include<stdio.h>
#include<math.h>

int main(){
    int T ,a ,b ,c ;
    scanf("%d",&T ) ;
    while (T-- && scanf("%d%d%d",&a ,&b ,&c) ){
          int d=sqrt(b*b-4*a*c) ;
          printf("%s\n",d*d==b*b-4*a*c?"Yes":"No") ;
    }
}
