#include <bits/stdc++.h>
using namespace std;

int solve(){
    long long n, m; cin >> n >> m;

    if (m<n-1) return -1;
    if (m>n*(n+1)/2) return -1;

    if (n==1){
        if (m<=1) return m;
        return -1;
    }
    if (n==2){
        if (m==1) return 1;
        if (m<=3) return 2;
        return -1;
    }

    if (m<=n+1) return 2;

    int l=3, r=n; 
    while (l!=r){
        int mid = (l+r)/2;
        if (n * (mid+1) / 2 >= m) r = mid;
        else l = mid+1;
    }
    return r;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    int T; cin >> T;
    for (int cs=1; cs<=T; cs++){
        int result = solve();
        cout << result << endl;
    }
}
