/* 
    Wilson's theorem
    (p-1)! = -1 (mod p)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef __int128 LLLL;

LLLL cntp(LLLL X, LLLL P){
    LL ans=0;
    while (X>0){
        ans += X/P;
        X/=P;
    }
    return ans;
}

LLLL POW(LLLL X, LLLL N, LLLL mod){
    LLLL ans=1;
    while (N>0){
        if (N%(LLLL)2){
            ans = ans*X%mod;
        }
        X = X*X%mod;
        N /= (LLLL)2;
    }
    return ans;
}

LLLL Inverse(LLLL X, LLLL mod){
    return POW(X,mod-2,mod);
}

const int MAXP = 100005;
const int MAXK = 11;

LLLL N, M; int K;
LLLL a[MAXK], p[MAXK];
LLLL Jp[MAXP];

void input(){
    LL _N, _M;
    scanf("%lld %lld %d", &_N, &_M, &K);
    N=(LLLL)_N;
    M=(LLLL)_M;

    LL pi;
    for (int i=0; i<K; i++){
        scanf("%lld", &pi);
        p[i] = (LLLL)pi;
    }
} 

void build(){
    for (int i=0; i<K; i++){
        LLLL cnt = (LLLL)0;
        cnt = cntp(N,p[i]) - cntp(M,p[i]) - cntp(N-M,p[i]);
        if (cnt>0){
            a[i]=(LLLL)0;
            continue;
        }

        Jp[0]=(LLLL)1;
        for (int j=1; j<= (int)p[i]; j++){
            Jp[j]=Jp[j-1]*(LLLL)j%p[i];
        }

        LLLL B=(LLLL)1;
        LLLL D=N;
        while (D>(LLLL)0){
            B = B * POW(Jp[p[i]-1],D/p[i],p[i]) % p[i];
            B = B * Jp[ (int)(D%p[i]) ] % p[i];
            D/=p[i];
        }

        LLLL A=(LLLL)1;
        D=M;
        while (D>(LLLL)0){
            A = A * POW(Jp[p[i]-1],D/p[i],p[i]) % p[i];
            A = A * Jp[ (int)(D%p[i]) ] % p[i];
            D/=p[i];
        }
        D=N-M;
        while (D>(LLLL)0){
            A = A * POW(Jp[p[i]-1],D/p[i],p[i]) % p[i];
            A = A * Jp[ (int)(D%p[i]) ] % p[i];
            D/=p[i];
        }

        a[i] = B*Inverse(A,p[i])%p[i];
    }
}

LLLL pM;
LLLL t[MAXK], Mi[MAXK];
void solve(){
    pM=(LLLL)1;
    for (int i=0; i<K; i++)pM*=p[i];
    
    for (int i=0; i<K; i++){
        Mi[i] = pM/p[i];
        t[i] = Inverse(Mi[i],p[i]);
    }

    LLLL ans=0;
    for (int i=0; i<K; i++){
        ans += a[i]*t[i]%pM*Mi[i]%pM;
        ans %= pM;
    }

    printf("%lld\n",(LL)ans);
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        input();
        build();
        //for (int i=0; i<K; i++)printf("X = %lld (mod %lld)\n",(LL)a[i],(LL)p[i]);
        solve();
    }
}
