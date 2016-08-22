#include<stdio.h>

char S[130] ,t ,ok ;

int walk(){
    if (S[t]=='('){
        t++ ; //(
        int L=walk() ;
        t++ ; //,
        int R=walk() ;
        t++ ; //)
        if (L!=R)ok=0 ;
        return L+R ;
    }
    else if ('0'<= S[t] && S[t]<='9'){
        int v ;
        sscanf(S+t,"%d",&v) ;
        while ('0'<= S[t] && S[t]<='9')t++ ;
        return v ;
    }

}

int main(){
    int T ;scanf("%d",&T) ;

    while (T-- && scanf("%s",S )){
        t=0 ,ok=1 ;
        walk() ;
        printf("%s\n",ok?"Yes":"No") ;
    }
}
