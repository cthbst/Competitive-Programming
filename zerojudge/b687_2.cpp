#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int maxn = 100000;
int n;
int st[20][maxn];
const int *a = st[0];

void build_sparse_table() {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1, len = 1; (len << 1) <= n; i++, len <<= 1)
        for (int j = n - (len << 1); j >= 0; j--)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + len]);
}

LL ans, m;
void query(int X, int Y) {
    int d = __lg(X), h;
    Y--;
    for (int l = n - X, r = n - (1 << d); l >= 0; --l, --r) {
        h = min(st[d][l], st[d][r]);
        if (h > Y) ans += h - Y;
    }
}

int main() {
    scanf("%d%lld", &n, &m);
    build_sparse_table();

    ans = 0;
    LL i = 0;
    for (i = 1; i * i < m; i++)
        if (m % i == 0LL && m / i <= 100000LL) {
            query((int)i, (int)(m / i));
            query((int)(m / i), (int)i);
        }
    if (i * i == m) query((int)i, (int)i);

    cout << ans << endl;
}
