#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    int cnt[105] = {0};
    int x;
    while (cin >> x) {
        if (x == 0) {
            break;
        } else if (x > 0) {
            cnt[x]++;
        } else if (x < 0) {
            cnt[-x]--;
        }
    }
    if (cnt[a] > 0 && cnt[b] > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    int T;
    cin >> T;
    int ans = 0;
    for (int cs = 1; cs <= T; cs++) {
        ans += solve(a, b);
    }
    cout << ans;
}
