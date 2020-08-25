#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, x[12], y[12];

    cin >> x[1];
    assert(x[1] == 0 || x[1] == 2 || x[1] == 5);

    cin >> n;
    assert(1 <= n && n <= 10);

    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        assert(y[i] == 0 || y[i] == 2 || y[i] == 5);
    }

    for (int i = 2; i <= n; i++) {
        if (i >= 3 && y[i - 2] == y[i - 1]) {
            if (y[i - 1] == 0) x[i] = 5;
            if (y[i - 1] == 2) x[i] = 0;
            if (y[i - 1] == 5) x[i] = 2;
        } else {
            x[i] = y[i - 1];
        }
    }

    bool finished = false;
    for (int i = 1; i <= n; i++) {
        cout << x[i] << ' ';
        if (x[i] != y[i]) {
            int d = y[i] - x[i];
            if (d == 5 || d == -2 || d == -3) {
                cout << ": Won at round " << i << '\n';
            } else {
                cout << ": Lost at round " << i << '\n';
            }
            finished = true;
            break;
        }
    }

    if (!finished) {
        cout << ": Drew at round " << n << '\n';
    }
}
