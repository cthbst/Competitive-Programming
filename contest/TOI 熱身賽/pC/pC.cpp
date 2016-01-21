#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100 ;
int n ,L ,a[maxn] ;

bool test(int l ,int r ){
    // l==0 || r==n-1
    if (l>=r)return 0 ;
    while (l+1<=r-1){
        if (a[l+1]-a[l]!=a[r]-a[r-1])return 0 ;
        l++ ,r-- ;
    }
    return 1 ;
}

int main(){
    cin >> n >> L ;
    for (int i=0 ;i<n ;i++ )
        scanf("%d",a+i) ;
    sort(a,a+n) ;
    int ans=test(0,n-1) ;
    for (int i=1 ;i<n-1 ;i++ )
        ans+=test(0,i)+test(i,n-1) ;
    cout<< ans <<endl ;
}
