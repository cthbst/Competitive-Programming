#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50004;
int n, p[MAXN];  // p[i] 是 i 所指向的人的編號

int main() {
    // 輸入 p[i]
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // 計算指向的人的編號是大於等於自己的編號的個數
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] >= i) {  // 指向的人的編號大於等於自己
            ans++;
        }
    }
    cout << ans << '\n';
}
