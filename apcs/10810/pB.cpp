#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;

int n, a[MAXN], b[MAXN];
int m, q[MAXN];

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> q[i];
    }
}

void modify(int opt) {
    for (int i = 0; i < n; i++) b[i] = a[i];

    if (opt == 1) {
        for (int i = 0; i < n / 2; i++) {
            a[i] = b[i * 2];
            a[i + n / 2] = b[i * 2 + 1];
        }
    } else if (opt == 2) {
        for (int i = 0; i < n / 2; i++) {
            a[i * 2] = b[i];
            a[i * 2 + 1] = b[i + n / 2];
        }
    } else {  // opt > 2
        int k = opt;
        for (int i = 0, j = n - k; i < n; i++) {
            a[i] = b[j];
            j = (j + 1) % n;
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    for (int i = m - 1; i >= 0; i--) {
        int opt = q[i];
        modify(opt);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}
