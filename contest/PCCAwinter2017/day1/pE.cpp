#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5003;

int n;
char s[MAXN];
int SG[MAXN];

void build(){
    SG[0]=0;
    SG[1]=1;
    for (int i=2; i<MAXN; i++){
        map<int,bool> mex;
        for (int d=1; d<=i; d++){
            mex[ SG[max(d-2,0)]^SG[max(i-d-1,0)] ]=1;
        }
        for (int j=0; ; j++){
            if (mex[j]==0){
                SG[i]=j;
                break;
            }
        }
    }
}

int solve(int l, int r){
    int ans=0;
    int cnt=0;

    for (int i=l+1; i<r; i++){
        if (s[i-1]==s[i+1]){
            cnt++;
        }
        else {
            ans ^= SG[cnt];
            cnt=0;
        }
    }
    ans^=SG[cnt];

    return ans;
}

int main(){
    build();

    scanf("%s",s+1);
    n = strlen(s+1);

    for (int i=2; i<n; i++)if (s[i-1]==s[i+1]){
        if ( solve(1,i-1)^solve(i+1,n) )continue;
        puts("First");
        printf("%d\n",i);
        return 0;
    }
    puts("Second");
}
