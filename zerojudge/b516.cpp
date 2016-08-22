#include<stdio.h>

char s[20] ;

int main(){
    int T ,i ; scanf("%d",&T ) ;

    while (T-- && scanf("%s",s)){
        for (i=0 ;s[i]>0 ;i++ )
            s[i]= 'A'+((s[i]-'A')+3)%26 ;
        puts(s) ;
    }
}
