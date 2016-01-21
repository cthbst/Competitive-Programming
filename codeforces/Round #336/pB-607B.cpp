#include<bits/stdc++.h>
using namespace std ;

const int INF = 1<<29 ;
const int maxn = 501 ;
int n ,a[maxn] ;
int dp[maxn][maxn] ;

int main(){
    cin >> n ;
    for (int i=0 ;i<n ;i++ )scanf("%d",a+i) ;

    for (int i=0 ;i<n ;i++ )dp[i][i]=1 ,dp[i+1][i]=1 ;
    for (int i=n-1 ;i>=0 ;i-- ){
        for (int j=i+1 ;j<n ;j++ ){
            dp[i][j]=INF ;
            for (int k=i ;k<j ;k++ )
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]) ;
            if (a[i]==a[j])dp[i][j]=min(dp[i][j],dp[i+1][j-1]) ;
        }
    }
    cout << dp[0][n-1] <<endl ;
}
