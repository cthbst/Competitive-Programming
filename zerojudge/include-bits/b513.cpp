#include<bits/stdc++.h>
using namespace std ;

const int maxn = 65536 ;
bool p[maxn] ;

void build_prime(){
    memset(p,1,sizeof(p)) ;
    p[0]=p[1]=0 ;
    for (int i=2 ;i<maxn ;i++ )if (p[i]==1){
        for (int j=i+i ;j<maxn ;j+=i )p[j]=0 ;
    }
}

int main(){
    build_prime() ;

    int T ,n ; cin >>T ;
    while (T-- && scanf("%d",&n )){
        puts(p[n]?"Y":"N") ;
    }
}
