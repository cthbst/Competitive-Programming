#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;

void input() {
    scanf("%d", &n);

    for (int i = 0, xi; i < n; i++) {
        scanf("%d", &xi);
        pq.push(xi);
    }
}

void solve() {
    long long ans = 0;

    while (pq.size() >= 2) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        pq.push(a + b);
        ans += a + b;
    }

    printf("%lld\n", ans);
}

int main() {
    input();
    solve();
}
