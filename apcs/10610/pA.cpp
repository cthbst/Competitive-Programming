#include <bits/stdc++.h>
using namespace std;

int main() {
    // 輸入 a, b, c
    int a, b, c;
    cin >> a >> b >> c;

    // 把非 0, 1 的數字轉成 1
    if (a != 0) a = 1;
    if (b != 0) b = 1;

    int cnt = 0;  // 記錄解的個數，如果為 0 表示無解

    if ((a && b) == c) {
        cout << "AND" << '\n';
        cnt++;
    }
    if ((a || b) == c) {
        cout << "OR" << '\n';
        cnt++;
    }
    if ((a ^ b) == c) {
        cout << "XOR" << '\n';
        cnt++;
    }
    if (cnt == 0) {
        cout << "IMPOSSIBLE" << '\n';
    }
}
