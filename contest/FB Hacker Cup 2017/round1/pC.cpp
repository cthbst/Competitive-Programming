#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 102;
const int MAXK = 5003;
const LL INF = 1LL<<60;

int N, M, K;
int S[MAXK], D[MAXK];
LL dis[MAXN][MAXN];
LL dp[MAXK];

void input(){
    scanf("%d %d %d", &N, &M, &K);

    for (int i=1; i<=N; i++){
        dis[i][i]=0;
        for (int j=1; j<i; j++){
            dis[i][j]=dis[j][i]=INF;
        }
    }

    int u, v, w;
    for (int i=0; i<M; i++){
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v]=dis[v][u]=min(dis[u][v],(LL)w);
    }

    S[0]=D[0]=1;
    for (int i=1; i<=K; i++){
        scanf("%d %d", &S[i], &D[i]);
    }
}

void FloydWarshall(){
    for (int k=1; k<=N; k++){
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

void solve(){
    input();
    FloydWarshall();

    for (int i=0; i<=K; i++){
        dp[i]=INF;
    }

    dp[0] = 0;
    dp[1] = dis[ D[0] ][ S[1] ] + dis[ S[1] ][ D[1] ];
    for (int i=2; i<=K; i++){
       dp[i] = min( dp[i] , dp[i-1] + dis[ D[i-1] ][ S[i] ] + dis[ S[i] ][ D[i] ]);

       dp[i] = min( dp[i] , dp[i-2] + dis[ D[i-2] ][ S[i-1] ] 
                                    + dis[ S[i-1] ][ S[i]   ]
                                    + dis[ S[i]   ][ D[i-1] ]
                                    + dis[ D[i-1] ][ D[i]   ]
                                    );
    }
    
    if (dp[K]==INF)puts("-1");
    else cout << dp[K] << endl;
}

int main(){
    int T; scanf("%d",&T);

    for (int t=1; t<=T; t++){
        printf("Case #%d: ",t);
        solve();
    }
}
