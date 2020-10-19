#include <bits/stdc++.h>
using namespace std;

long long Merge(const vector<int> &a) {
    int n = a.size() / 2;
    int mid = n / 2;
    vector<int> cnt(n + 1);
    long long ans = 0;
    for (int i = 0, psum = 0; i < (int)a.size(); i++) {
        if (a[i] <= mid) {
            psum++;
        } else {  // a[i] > mid
            if (cnt[a[i]] == 0) {
                ans -= psum;
                cnt[a[i]]++;
            } else {  // cnt[a[i]] == 1
                ans += psum;
            }
        }
    }
    return ans;
}

long long DC(const vector<int> &a) {
    if (a.size() <= 2) return 0;
    int n = a.size() / 2;
    int mid = n / 2;
    vector<int> aSmall, aLarge;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] <= mid) {
            aSmall.push_back(a[i]);
        } else {  // a[i] > mid
            aLarge.push_back(a[i] - mid);
        }
    }
    return DC(aSmall) + DC(aLarge) + Merge(a);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    cout << DC(a) << endl;
    return 0;
}
