#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;

int P, K, N;
int a[MAXN];
int SG[MAXN];

int build(){
    memset(SG,0,sizeof(SG));

    for (int i=1; i<=N; i++){
        map<int,bool> mex;

        for (int k=0; k<=K && i-k>0; k++){
            int j = (i-k) - a[i-k];
            if (j>=0)mex[ SG[j] ] = 1;
        }
        for (int j=0; ; j++)if (mex[j]==0){
            SG[i]=j;
            break;
        }
    }
}

int main(){
    while ( ~scanf("%d%d",&P, &K) ){
        int ans=0;
        for (int i=0; i<P; i++){
            scanf("%d",&N);
            for (int j=1; j<=N; j++){
                scanf("%d",&a[j]);
            }
            build();
            ans ^= SG[N];
        }
        if (ans!=0)puts("Alice can win.");
        else puts("Bob will win.");
    } 
}
