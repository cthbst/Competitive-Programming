#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD = 1000000007LL;
const int MAXN = 2001;

int N, M;
int R[MAXN];
map<int,int> J;
vector<int> query;

void setJ(){
    sort(query.begin(),query.end());
    int P=1;
    for (int i=1,j=0; j<query.size(); i++){
        P = (LL)P*i%MOD;
        if (i==query[j]){
            J[i]=P;
            j++;
        }
    }
}

int pow(int a, int n){
    int re=1;
    
    while (n>0){
        if (n&1)
            re = (LL)re*a%MOD;
        a = (LL)a*a%MOD;
    }
    return re;
}

int inverse(int x){
    return pow(x,MOD-2);
}

int Com(int n, int m){
    if (m<0 || m>n)return 0;
    int re = J[n];
    re = (LL)re*inverse(J[m])%MOD;
    re = (LL)re*inverse(J[n-m])%MOD;
    return re;
}

void input(){
    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; i++){
        scanf("%d",&R[i]);
    }
}



void solve(){
    input();
    query.clear();

    setJ();
}

int main(){
    int T; scanf("%d",&T);

    for (int t=1; t<=T; t++){
        printf("Case #%d: ",t);
        solve();
    }
}
