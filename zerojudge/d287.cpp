#include<stdio.h>

typedef long long int LL ;

LL gcd(LL a ,LL b ){
    if (!b)return a ;
    return gcd(b,a%b) ;
}
int main(){
    LL a ,b ;
    while (~scanf("%lld%lld",&a ,&b )){
        printf("%lld\n",a+b-gcd(a,b)) ;
    }
}
