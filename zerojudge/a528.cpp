#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

char S[1000][103] ;

bool cmp(int a ,int b ){
    char *p = S[a] ;
    char *q = S[b] ;
    if (p[0]=='-' && q[0]!='-') return 1 ;
    if (p[0]!='-' && q[0]=='-') return 0 ;
    int lp = strlen(p) ;
    int lq = strlen(q) ;
    if (p[0]=='-'){
        if (lp!=lq)return lp>lq ;
        for (int i=1 ;i<lp ;i++ ){
            if (p[i]!=q[i])return p[i]>q[i] ;
        }
        return 0 ;
    }
    else {
        if (lp!=lq)return lp<lq ;
        for (int i=0 ;i<lp ;i++ ){
            if (p[i]!=q[i])return p[i]<q[i] ;
        }
        return 0 ;
    }
}

int a[1000] ;

int main(){
    int n ;
    while (~scanf("%d",&n )){
        for (int i=0 ;i<n ;i++ ){
            scanf("%s",S[i]) ;
            a[i]=i ;
        }
        sort(a,a+n,cmp) ;
        for (int i=0 ;i<n ;i++ ){
            puts(S[ a[i] ]) ;
        }
    }
}
