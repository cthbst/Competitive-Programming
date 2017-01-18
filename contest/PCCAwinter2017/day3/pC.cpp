#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int MAXN = 102;
const int MAXW = 100005;

int Cash, N;
int c[MAXN], w[MAXN];
bool dp[MAXN][MAXW];

void input(){
    for (int i=1; i<=N; i++)
        scanf("%d", &w[i]);
    for (int i=1; i<=N; i++)
        scanf("%d", &c[i]);
}

void solve(){
    for (int i=1; i<=N; i++){
        if (w[i]>Cash)continue;
        if (w[i]*c[i]>=Cash){
            for (int j=0; j<w[i]; j++){
                dp[i][j] = dp[i-1][j];
            }
            for (int j=w[i]; j<=Cash; j++){
                dp[i][j] = (dp[i-1][j] | dp[i][j-w[i]]);
            }
        }
        else {
            for (int j=0; j<w[i]; j++){
                int sum=0;
                for (int k=0; k<=c[i]; k++){
                    int idx = j+w[i]*k;
                    sum += dp[i-1][idx];
                    dp[i][idx] = (sum>0);
                }
                for (int k=c[i]+1; k*w[i]<=Cash; k++){
                    int idx = j+w[i]*k;
                    sum -= dp[i-1][idx-w[i]*(c[i]+1)];
                    sum += dp[i-1][idx];
                    dp[i][idx] = (sum>0);
                }
            }
        }
    }
}

int main(){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    while ( ~scanf("%d %d", &N, &Cash) ){
        if (N==0 && Cash==0)return 0;

        input();
        solve();
        
        int ans=0;
        for (int i=1; i<=Cash; i++){
            ans += dp[N][i];
        }
        printf("%d\n",ans);
    }
}
