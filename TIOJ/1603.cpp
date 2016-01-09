/* sparse table */

#include<bits/stdc++.h>
using namespace std ;

typedef unsigned int uint ;

uint getint(){
    char c ; uint re=0 ;
    while (isdigit(c=getchar()))
        re=10*re+c-'0' ;
    return re ;
}

const int maxn = 100030 ;
const int lgN = 17 ;

uint st[2][lgN][maxn] ;

void build(int n ){
    for (int i=0 ;i<n ;i++ )
        st[0][0][i]=st[1][0][i]=getint() ;
    for (int i=1 ,len=2 ;len<=n ;i++ ,len<<=1)
        for (int j=n-len ;j>=0 ;j-- )
            st[0][i][j]=min(st[0][i-1][j],st[0][i-1][j+(len>>1)]) ,
            st[1][i][j]=max(st[1][i-1][j],st[1][i-1][j+(len>>1)]) ;
}

uint query(int l ,int r){
    int d = __lg(++r-l) ;
    return max(st[1][d][l],st[1][d][r-(1<<d)])-
           min(st[0][d][l],st[0][d][r-(1<<d)]);
}

int main(){
    int n = (int)getint() ,m= (int)getint() ;
    build(n) ;

    for (int i=0 ,l ,r ;i<m ;i++ ){
        l=(int)getint() ,r=(int)getint() ;
        printf("%u\n",query(l-1,r-1)) ;
    }
}
