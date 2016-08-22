#include<stdio.h>

const int MOD = 10000 ;
int main(){
    char c ;
    int ans=0 ;
    int pro=1 ;
    int num=0 ;
    while (c=getchar()){
        if (c=='\n' || c==EOF)break ;
        if (c=='+'){
            num%=MOD ;
            pro=pro*num%MOD ;
            ans=(ans+pro)%MOD ;
            pro=1 ;
            num=0 ;
        }
        else if (c=='*'){
            num%=MOD ;
            pro=pro*num%MOD ;
            num=0 ;
        }
        else {
            num=10*num+c-'0' ;
        }
    }
    num%=MOD ;
    pro=pro*num%MOD ;
    ans=(ans+pro)%MOD ;
    printf("%d\n",ans) ;
}
