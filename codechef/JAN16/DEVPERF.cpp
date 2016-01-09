#include<bits/stdc++.h>
using namespace std ;

char s[1030] ;

int main(){
    int T ; cin >>T ;

    int n ,m ;
    while (T-- && scanf("%d%d",&n ,&m )){
        int x=2000 ,X=-1 ,y=2000 ,Y=-1 ;
        for (int i=0 ;i<n ;i++ ){
            scanf("%s",s) ;
            for (int j=0 ;j<m ;j++ )if (s[j]=='*'){
                y=min(y,i) ,Y=max(Y,i) ;
                x=min(x,j) ,X=max(X,j) ;
            }
        }
        if (x==2000)puts("0") ;
        else printf("%d\n",max((X-x+3)/2,(Y-y+3)/2)) ;
    }
}
