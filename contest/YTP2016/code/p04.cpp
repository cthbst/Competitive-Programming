// by 趙俊凱
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main(){
    cin >> n;
    a.resize(n);
    for (auto &x:a)cin >> x;
    sort(a.begin(),a.end());

    int ans= a[0]*(n-1);
    for (int i=1; i<n; i++){
        ans += a[i]*(n-i);
    }
    cout << ans;
}
