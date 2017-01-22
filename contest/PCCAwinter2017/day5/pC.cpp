#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;
const LL MOD = 1000000007;
const LL INF = MOD;
const LL MAXN = 500000;
LL a[MAXN], pos=4;
LL mS[MAXN], mV[MAXN];

void build(){
    a[1]=1;
    a[2]=a[3]=2;

    LL sum = a[1]+a[2]+a[3];
    for (LL i=3; pos<MAXN ; i++){
        for (LL j=0; j<a[i] && pos<MAXN; j++, pos++){
            a[pos] = i;
            sum += a[pos];
        }
    }

    mS[0]=mV[0]=0LL;
    for (LL ai=1; ai<MAXN; ai++){
        mS[ai]=mS[ai-1];
        mV[ai]=mV[ai-1];
        mV[ai]+=ai%MOD*(mS[ai]%MOD*a[ai]%MOD+a[ai]*(a[ai]+1LL)/2LL%MOD)%MOD; mV[ai]%=MOD;
        mS[ai]+=a[ai];
    }
}

void solve(){
    LL n; cin >> n;
    
    LL l=1, r=MAXN-1;
    while (l!=r){
        LL mid = (l+r)>>1;
        if (mS[mid]>n)r=mid;
        else l=mid+1;
    }
    LL ai=l;
    LL S=mS[l-1];
    LL V=mV[l-1];

    LL d = n-S;
    V+=ai%MOD*(S%MOD*d%MOD+d*(d+1LL)/2LL%MOD)%MOD;
    V%=MOD;

    cout << V << endl;
}

int main(){
    build();
    int T; scanf("%d",&T);
    
    while (T--){
        solve();
    }
}
