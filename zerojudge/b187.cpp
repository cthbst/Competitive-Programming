#include<stdio.h>

int main(){
    puts("十六進位表示法  相對應的十進位表示法") ;

    char s[3] ;
    while(~scanf("%s",s)){
        int x , y ;
        if ('0'<=s[0] && s[0]<='9')x=s[0]-'0' ;
        else x=s[0]-'A'+10 ;
        if ('0'<=s[1] && s[1]<='9')y=s[1]-'0' ;
        else y=s[1]-'A'+10 ;
        int ans = x*16+y ;
        printf("      %s                 %d\n",s ,ans ) ;
    }
}
