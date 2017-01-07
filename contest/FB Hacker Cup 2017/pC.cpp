#include <bits/stdc++.h>
using namespace std;

const int CNT_DICE=6;
const int MAXT=25;
const int MAXN=600;
const int dice[CNT_DICE] = {4, 6, 8, 10, 12, 20};

double dp[CNT_DICE][MAXT][MAXN]; // dice, times, sum
double PSD[CNT_DICE][MAXT][MAXN]; //prifix sum dp

void build(){
    for (int d=0; d<CNT_DICE; d++){
        fill(dp[d][0],dp[d][0]+MAXN,0.0);
        dp[d][0][0]=1.0;

        double p = 1.0/dice[d];
        for (int t=0; t<MAXT-1; t++){
            fill(dp[d][t+1],dp[d][t+1]+MAXN,0.0);
            for (int w=1; w<=dice[d]; w++){
                for (int i=0; i+w<MAXN; i++){
                    dp[d][t+1][i+w] += dp[d][t][i]*p;
                }
            }
        }
    }

    for (int d=0; d<CNT_DICE; d++){
        for (int t=0; t<MAXT; t++){
            PSD[d][t][0]=dp[d][t][0];
            for (int i=1; i<MAXN; i++){
                PSD[d][t][i] = PSD[d][t][i-1]+dp[d][t][i];
            }
        }
    }
}

int H;
double parser(){
    char s[100]; scanf("%s",s);
    int X, Y, Z=0;

    for (int i=0; s[i]!=0; i++){
        if (s[i]=='+'){
            Z=1;
        }
        else if (s[i]=='-'){
            Z=-1;
        }
    }

    X = strtol(strtok(s,"d"),NULL,10);
    Y = strtol(strtok(NULL,"+-"),NULL,10);
    if (Z!=0){
        Z *= strtol(strtok(NULL,""),NULL,10);
    }

    //printf("%d %d %d\n",X,Y,Z);

    int h = H-Z;
    if (h<=0)return 1.0;
    if (h>400)return 0.0;

    int id=0;
    for (int i=0; i<CNT_DICE; i++){
        if (dice[i]==Y)id=i;
    }
    return PSD[id][X][400]-PSD[id][X][h-1];
}

void solve(){
    int S; cin >> H >> S;
    double ans=0.0;
    for (int i=0; i<S; i++){
        ans = max(ans, parser() );
    }
    printf("%.6f",ans);
}
int main(){
    freopen("fighting_the_zombie.txt","r",stdin);
    freopen("pC.out","w",stdout);
    build();

    int T;
    scanf("%d",&T);

    for (int t=1; t<=T; t++){
        printf("Case #%d: ", t);
        solve();
        printf("\n");
    }
}
