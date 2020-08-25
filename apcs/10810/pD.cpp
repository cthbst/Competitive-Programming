#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int INF = N * N;

int n, m;
int a[N][N];

int S[N][N];
int dp[N][N][N][N];

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            S[i][j] = a[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }
}

int cost(int xl, int xr, int yl, int yr) {
    xl--, yl--;
    int one = S[xr][yr] - S[xl][yr] - S[xr][yl] + S[xl][yl];
    int area = (xr - xl) * (yr - yl);
    return min(one, area - one);
}

int solve(int xl, int xr, int yl, int yr) {
    if (xl > xr || yl > yr) return INF;
    int &ans = dp[xl][xr][yl][yr];
    if (ans != -1) return ans;
    if (cost(xl, xr, yl, yr) == 0) return ans = 0;
    ans = INF;
    ans = min(ans, cost(xl, xl, yl, yr) + solve(xl + 1, xr, yl, yr));
    ans = min(ans, cost(xr, xr, yl, yr) + solve(xl, xr - 1, yl, yr));
    ans = min(ans, cost(xl, xr, yl, yl) + solve(xl, xr, yl + 1, yr));
    ans = min(ans, cost(xl, xr, yr, yr) + solve(xl, xr, yl, yr - 1));
    return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    memset(dp, -1, sizeof(dp));
    cout << solve(1, n, 1, m) << '\n';
}
