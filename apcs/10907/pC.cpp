#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> a, S;

void init() {
    cin >> n >> m;
    a.resize(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    S.resize(2 * n);
    long long sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += a[i];
        S[i] = sum;
    }
}

int next_pos(int pos, long long target) {
    target += S[pos] - a[pos];
    int L = pos;
    int R = pos + n;
    pos = lower_bound(S.begin() + L, S.begin() + R, target) - S.begin();
    return (pos + 1) % n;
}

int main() {
    init();
    int pos = 0;
    for (int cs = 1; cs <= m; cs++) {
        int target;
        cin >> target;
        pos = next_pos(pos, target);
    }
    cout << pos << endl;
}
