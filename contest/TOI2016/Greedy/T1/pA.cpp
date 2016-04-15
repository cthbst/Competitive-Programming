#include<bits/stdc++.h>
using namespace std ;

const int maxn=10000 ;
int n ,m ,a[maxn] ,b[maxn] ;

void solve(){
    scanf("%d%d",&n ,&m ) ;
    for (int i=0 ;i<n ;i++ )scanf("%d",&a[i]) ;
    for (int i=0 ;i<m ;i++ )scanf("%d",&b[i]) ;
    sort(a,a+n) ;
    sort(b,b+m) ;

    int u=0 ,v=0 ,ans=0 ;
    //-----------------------
    for (;u<n && v<m ;u++ ){
        while (v<m && a[u]>b[v])v++ ;
        if (v==m)break ;
        ans+=b[v++] ;
    }
    //output ----------------
    if (u<n)puts("-1") ;
    else printf("%d\n",ans ) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    while (T--)solve() ;
}
