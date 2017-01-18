#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int MAXN = 15;
const int MAXW = 100005;

int Cash, N;
int c[MAXN], w[MAXN];
bool dp[MAXN][MAXW];
pii K[MAXW];

void input(){
    for (int i=1; i<=N; i++){
        scanf("%d %d", &c[i], &w[i]);
        if (c[i]==0 || w[i]==0 || w[i]>Cash){
            i--, N--;
        }
    }
}

int solve(){
    for (int i=1; i<=N; i++){
        for (int j=0; j<w[i]; j++){
            int sum=0;
            for (int k=0; k<=c[i] && k*w[i]<=Cash; k++){
                sum += dp[i-1][j+k*w[i]];
                dp[i][j+k*w[i]] = (sum>0);
            }
            for (int k=c[i]+1; k*w[i]<=Cash; k++){
                int idx = j+k*w[i];
                sum -= dp[i-1][idx-w[i]*(c[i]+1)];
                sum += dp[i-1][idx];
                dp[i][idx] = (sum>0);
            }
        }
    }

    for (int i=Cash; i>=0; i--){
        if (dp[N][i])return i;
    }
}

int main(){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    while ( ~scanf("%d %d", &Cash, &N) ){
        input();
        printf("%d\n",solve());
    }
}
