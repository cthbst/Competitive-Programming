#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 302;
const LL INF = 1LL<<60;

int N, M;
LL C[MAXN][MAXN];
LL dp[MAXN][MAXN];

void input(){
    scanf("%d %d", &N, &M);
    
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            scanf("%lld",&C[i][j]);
        }
    }
    
    for (int i=1; i<=N; i++){
        sort(C[i]+1,C[i]+1+M);
        C[i][0]=0;
        for (int j=1; j<=M; j++){
            C[i][j] += C[i][j-1];
        }
        for (int j=1; j<=M; j++){
            C[i][j] += j*j;
        }
    }
}

void solve(){
    input();

    dp[0][0]=0;
    for (int i=1; i<=N; i++){
        dp[0][i]=INF;
    }

    for (int i=1; i<=N; i++){
        for (int j=0; j<i; j++){
            dp[i][j]=INF;
        }
        for (int j=i; j<=N; j++){
            dp[i][j]=dp[i-1][j];
            for (int k=max(0,j-M); k<j; k++){
                dp[i][j] = min(dp[i][j],dp[i-1][k]+C[i][j-k]);
            }
        }
    }

    cout << dp[N][N] << endl;
}

int main(){
    int T; scanf("%d",&T);

    for (int t=1; t<=T; t++){
        printf("Case #%d: ",t);
        solve();
    }
}
