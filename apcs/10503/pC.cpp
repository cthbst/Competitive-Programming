/* APCS 2016 March problem C */

#include <bits/stdc++.h>
using namespace std;

const int MAXM = 10000007;

int n;
int box[MAXM];

// ...+....-...  取 prefix sum 前
// ...+++++....  取 prefix sum 後

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        // 為了讓取 prefix sum 後 box[l]...box[r-1] 都增加 1
        // 要在 box[l] 加一，box[r] 減一
        box[l]++;
        box[r]--;
    }

    int sum = 0;  // 紀錄 prefix sum
    int ans = 0;

    // 取完 prefix sum 後大於 0 的格子就是有被覆蓋的
    for (int i = 0; i < MAXM; i++) {
        sum += box[i];
        if (sum > 0) ans++;
    }
    cout << ans << '\n';
}
