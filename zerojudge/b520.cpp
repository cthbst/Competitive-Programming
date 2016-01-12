#include<bits/stdc++.h>
using namespace std ;

int getint(){
    char c ; int re=0 ;
    while ( !isdigit( c=getchar() ) ) ;
    do {
        re=10*re+c-'0' ;
    }while (isdigit( c=getchar() )) ;
    return re ;
}

int main(){
    int T = getint() ;
    int a[5] ,b[5] ;
    while (T--){
        for (int i=0 ;i<5 ;i++ )a[i]=getint() ;
        for (int i=0 ;i<5 ;i++ )b[i]=getint() ;
        sort(a,a+5) ,sort(b,b+5) ;
        int ans=0 ;
        for (int l=0 ,r=0 ;l<5 && r<5 ;){
            if (a[l]==b[r])ans++ ,l++ ,r++ ;
            else if (a[l]<b[r])l++ ;
            else if (a[l]>b[r])r++ ;
        }
        cout <<ans <<endl ;
    }
}
