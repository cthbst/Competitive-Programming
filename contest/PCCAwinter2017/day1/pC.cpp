#include <bits/stdc++.h>
using namespace std;

const int MAXFIB = 20;
const int MAXN = 1003;
int fib[MAXFIB];
int SG[MAXN];

void build_fib(){
    fib[0]=fib[1]=1;
    for (int i=2; i<MAXFIB; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
}

void build_SG(){
    SG[0]=0;

    for (int i=1; i<MAXN; i++){
        map<int,bool> mex;

        for (int j=1; i-fib[j]>=0; j++){
            int k = i-fib[j];
            mex[ SG[k] ]=1;
        }
        for (int j=0; j<MAXN; j++){
            if (mex[j]==0){
                SG[i]=j;
                break;
            }
        }
    }
}

int main(){
    build_fib();
    build_SG();

    int m, n, p;
    while ( ~scanf("%d %d %d", &m, &n ,&p) ){
        if (m==0 && n==0 && p==0)return 0;

        int ans = SG[m]^SG[n]^SG[p];
        puts(ans==0?"Nacci":"Fibo");
    }
}
