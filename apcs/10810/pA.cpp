#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40;

int n, a[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 3; i < n; i++) {
        if (a[i] - a[i - 1] >= 5 || a[i] - a[i - 1] <= -5) {
            vector<int> v{a[i - 1], a[i - 2], a[i - 3]};
            sort(v.begin(), v.end());
            a[i] = v[1];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}
