#include <bits/stdc++.h>
using namespace std;

int N, K;

int SG(int n){
    if (n==0)return 0;
    
    static map<int,int> mem;
    
    int &ans = mem[n];
    if (ans!=0)return ans;


    if (n%2==1){
        if (n>10)
            return 0;
        else 
            return ans = !SG(n-1);
    }
    else {
        map<int,bool> mex;

        mex[ SG(n-1) ]=1;
        mex[ SG(n/2)*K ]=1;
        
        for (int i=0; i<3; i++){
            if (mex[i]==0)return ans = i;
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    K%=2;

    int ans=0;
    for (int i=0, ai; i<N; i++){
        scanf("%d",&ai);
        ans ^= SG(ai);
    }

    puts(ans==0?"Nicky":"Kevin");
}
