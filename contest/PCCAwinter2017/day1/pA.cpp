#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, n, r, c;
    scanf("%d %d %d %d",&m,&n,&r,&c);

    int ans=0;
    ans ^= r;
    ans ^= c;
    ans ^= m-r-1;
    ans ^= n-c-1;

    puts(ans==0?"Hansel":"Gretel");
}

int main(){
    int T; scanf("%d",&T);

    while (T--){
        solve();
    }
}
