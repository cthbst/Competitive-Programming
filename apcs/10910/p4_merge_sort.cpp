// Copyright (C) Algo Seacow. 2020. All Rights Reserved.
#include <bits/stdc++.h>
using namespace std;

long long DC(vector<pair<int, int>> &a) {
    int n = a.size();
    if (n <= 1) return 0;
    int mid = n / 2;
    vector<pair<int, int>> aLeft(a.begin(), a.begin() + mid);
    vector<pair<int, int>> aRight(a.begin() + mid, a.end());

    long long ans = 0;
    ans += DC(aLeft);
    ans += DC(aRight);

    vector<pair<int, int>> tmp;
    size_t ptrl = 0, ptrr = 0;
    while (ptrl < aLeft.size() && ptrr < aRight.size()) {
        if (aLeft[ptrl].first < aRight[ptrr].first) {
            tmp.push_back(aLeft[ptrl++]);
        } else {
            ans += ptrl * aRight[ptrr].second;
            tmp.push_back(aRight[ptrr++]);
        }
    }
    while (ptrl < aLeft.size()) {
        tmp.push_back(aLeft[ptrl++]);
    }
    while (ptrr < aRight.size()) {
        ans += ptrl * aRight[ptrr].second;
        tmp.push_back(aRight[ptrr++]);
    }
    a = tmp;

    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(2 * n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if (cnt[x] == 0) {
            a[i] = {x, -1};
            cnt[x] = 1;
        } else {
            a[i] = {x, 1};
        }
    }
    cout << DC(a) << endl;
    return 0;
}
