#include<stdio.h>
#define M 1234567
int main(){
    int n ;
    while (~scanf("%d",&n ) ){
          n-- ;
          long long int p=2 ,ans=1 ;
          while (n>0){
                if (n&1)ans*=p ;
                ans%=M ;
                p*=p ;
                p%=M ;
                n/=2 ;
          }
          if (n==-1)printf("0\n") ;
          else printf("%lld\n",ans) ;
    }
}
