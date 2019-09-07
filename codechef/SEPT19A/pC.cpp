#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
int A, B, C; 

int cal(int b){ // b*b < (a-1)*(c-1)
    long long result = 0;
    // (a-1) <= b
    for (int a=2; a<=A && a-1<=b; a++){
        int l = b * b / (a-1) + 2;
        if (l>C) continue;
        result += C-l+1;
    }

    // (c-1) <= b
    for (int c=2; c<=C && c-1<=b; c++){
        int l = b * b / (c-1) + 2;
        if (l>A) continue;
        result += A-l+1;
    }

    // (a-1) > b && (c-1) > b
    if (A > b+1 && C > b+1){
        result += (long long) (A-b-1) * (C-b-1) % MOD;
    }

    return result % MOD;
} 

void solve(){
    cin >> A >> B >> C;

    long long ans = 0;
    for (int b = 1; b <= B; b++){
        ans += cal(b);
    } 
    cout << ans % MOD << '\n';
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    int T; cin >> T;
    for (int cs=1; cs<=T; cs++){
        solve();
    }
}
