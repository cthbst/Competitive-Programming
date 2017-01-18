#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;
long long dp[MAXN][MAXN][1<<10];

int n, m;

void solve(){
    memset(dp[0][0],0,sizeof(dp[0][0]));

    int U = (1<<m)-1;
    for (int i=0; i<n; i++){
        if (i==0){
            dp[0][0][U^1]=1;
        }
        else { 
            for (int S=0; S<=U; S++){
                dp[i][0][S]=dp[i-1][m-1][S^1];
            }
        }

        for (int j=1; j<m; j++){
            int b = (1<<j);
            for (int S=0; S<=U; S++){
                dp[i][j][S] = dp[i][j-1][S^b];
                if ( (S&b) && (S&(b>>1)) ){
                    dp[i][j][S] += dp[i][j-1][S^(b>>1)];
                }
            }
        }
    }
    printf("%lld\n",dp[n-1][m-1][U]);
}

int main(){
    while (~scanf("%d %d", &n, &m)){
        if (n<m)swap(n,m);
        solve();
    }
}
