#include<bits/stdc++.h>
using namespace std ;

const int maxn = 10000 ;
int n ,a[maxn] ,b[maxn] ;

void solve(){
    for (int i=0 ;i<n ;i++ )scanf("%d",&a[i]) ;
    for (int i=0 ;i<n ;i++ )scanf("%d",&b[i]) ;
    sort(a,a+n) ;
    sort(b,b+n) ;
    int ans=0 ,l=0 ,r=n-1 ;
    for (int i=0 ;i<n ;i++ ){
        if (b[i]>a[l]) l++ ,ans++ ;
        else r-- ;
    }
    printf("%d\n",ans );
}

int main(){
    while (~scanf("%d",&n) && n!=0 )solve() ;
}
