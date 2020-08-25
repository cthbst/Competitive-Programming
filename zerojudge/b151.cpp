#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    priority_queue<long long, vector<long long>, greater<long long> > pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long ans = 0;
    while (pq.size() >= 2) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    cout << ans << '\n';

    return 0;
}
