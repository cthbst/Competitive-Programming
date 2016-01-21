#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100000 ;
typedef pair<int,int> ii ;
int n ,dp[maxn] ;
ii a[maxn] ;

int main(){
    cin >> n ;
    for (int i=0 ;i<n ;i++ )
        scanf("%d%d",&a[i].first ,&a[i].second ) ;
    sort(a,a+n) ;

    dp[0]=0 ;
    for (int i=1 ;i<=n ;i++ ){
        int l=0 ,r=i-1 ,p=a[i].first-a[i].second ;
        while (l!=r){
            int m=(l+r)>>1 ;
            a[m].first>=p ? (r=m) : (l=m+1) ;
        }
        if (a[l].first>=p)l-- ;
        if (l<0)dp[i]=i ;
        else dp[i] = i+dp[l]-l-1 ;
    }
    int ans=1<<29;
    for (int i=0 ;i<n ;i++ )
        ans = min(ans, n-i-1+dp[i] ) ;
    cout << ans <<endl ;
}
