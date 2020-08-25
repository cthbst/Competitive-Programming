#include <bits/stdc++.h>
using namespace std;

struct Item {
    int w, f;

    // 定義 Item 型別的比較依據
    bool operator<(const Item &rhs) const {
        return (double)w / f < (double)rhs.w / rhs.f;
    }
};

const int MAXN = 100005;
int n;
Item items[MAXN];  // 箱子們

int main() {
    // 輸入 items
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> items[i].w;
    }
    for (int i = 0; i < n; i++) {
        cin >> items[i].f;
    }
    sort(items, items + n);

    // 計算總共需要用的能量總和
    long long ans = 0;
    long long sumW = 0;
    for (int i = 0; i < n; i++) {
        ans += (long long)sumW * items[i].f;
        sumW += items[i].w;
    }
    cout << ans << '\n';
}
