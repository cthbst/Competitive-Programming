#include <bits/stdc++.h>
using namespace std;

const int MAXN = 252;
const int INF = 1<<29;

int n, a[MAXN]; // 1 base
int PSA[MAXN]; // prifix sum a
int dp[MAXN][MAXN];
int K[MAXN][MAXN]; 
/*********************************
 K(i,j-1) <= K(i,j) <= K(i+1,j)
**********************************/

void input(){
    for (int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    PSA[0]=0;
    for (int i=1; i<=n; i++){
        PSA[i] = PSA[i-1] + a[i];
    }
}

inline int sum(int l, int r){
    if (l>r)return 0;
    return PSA[r]-PSA[l-1];
}

inline int cal(int i, int j ,int k){
    return dp[i][k-1] + sum(i,k-1)
          +dp[k+1][j] + sum(k+1,j);
}

void solve(){
    for (int i=1; i<=n; i++){
        dp[i][i]=0;
        K[i][i]=i;
    }

    for (int i=n; i>=1; i--){
        for (int j=i+1; j<=n; j++){
            K[i][j]=K[i][j-1];
            dp[i][j]=cal(i,j,K[i][j]);

            for (int k=K[i][j-1]; k<=K[i+1][j]; k++){
                int Cal = cal(i,j,k);
                if ( Cal < dp[i][j] ){
                    dp[i][j]=Cal;
                    K[i][j]=k;
                }
            }
        }
    }
    printf("%d\n",dp[1][n]);
}

int main(){
    while ( ~scanf("%d",&n) ){
        input();
        solve();
    }
}
