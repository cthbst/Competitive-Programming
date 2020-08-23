#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int k, const vector<int> &a) {
    int n = a.size();

    vector<pair<int, int>> q;  // <islower, cnt>
    q.push_back({a[0], 1});
    for (int i = 1; i < n; i++) {
        if (q.back().first == a[i]) {
            q.back().second++;
        } else {
            q.push_back({a[i], 1});
        }
        for (int i = 0; i < q.size(); i++) {
            cout << q[i].second << ' ';
        }
        cout << endl;
    }

    int ans = 0, cnt = 0;
    for (int i = 0; i < (int)q.size(); i++) {
        if (q[i].second < k) {
            cnt = 0;
        } else if (q[i].second == k) {
            cnt += k;
            ans = max(ans, cnt);
        } else if (q[i].second > k) {
            cnt += k;
            ans = max(ans, cnt);
            cnt = k;
        }
    }
    cout << ans << '\n';
}

int main() {
    int k;
    string s;
    while (cin >> k >> s) {
        vector<int> a(s.size());
        for (int i = 0; i < s.size(); i++) {
            a[i] = islower(s[i]);
        }
        solve(k, a);
    }
    return 0;
}
