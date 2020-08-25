#include <bits/stdc++.h>
using namespace std;

int s, t, m, n, r;
int X[12][102], Y[12][102];
int R[12][102], D[12][102];

void init() {
    cin >> s >> t >> m >> n >> r;
    assert(1 <= s && s <= m && m <= 10);
    assert(1 <= t && t <= n && n <= 100);

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < t; j++) {
            cin >> Y[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> X[i][j];
        }
    }
}

void solve() {
    int cnt = 0;
    int mi = 1e9;

    for (int bi = 0; bi + s <= m; bi++) {
        for (int bj = 0; bj + t <= n; bj++) {
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < t; j++) {
                    R[bi][bj] += (X[bi + i][bj + j] != Y[i][j]);
                    D[bi][bj] += (X[bi + i][bj + j] - Y[i][j]);
                }
            }
            if (D[bi][bj] < 0) D[bi][bj] *= -1;
            if (R[bi][bj] <= r) {
                cnt++;
                mi = min(mi, D[bi][bj]);
            }
        }
    }
    if (cnt == 0) {
        cout << 0 << '\n' << 0 << '\n';
    } else {
        cout << cnt << '\n' << mi << '\n';
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    solve();
}
