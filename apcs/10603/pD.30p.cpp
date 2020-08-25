#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 50004;
int n, k;
int a[MAXN];

// 檢查一個直徑 D 是否可以滿足題意
bool check(int D) {
    int cnt = 0, left = -INF;
    for (int i = 0; i < n; i++) {
        if (a[i] - left > D) {
            left = a[i];
            cnt++;
        }
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    // 列舉 d
    int d = 0;
    while (check(d) == 0) d++;
    cout << d << '\n';
}
