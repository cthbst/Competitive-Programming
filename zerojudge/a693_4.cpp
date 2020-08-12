#include <stdio.h>

#include <algorithm>
using namespace std;

#define Max 100010
long long int tree[4 * Max];

void set_tree(int n, int l, int r) {
    if (l == r) {
        scanf("%lld", &tree[n]);
    } else {
        int m = (l + r) / 2;
        set_tree(2 * n, l, m);
        set_tree(2 * n + 1, m + 1, r);
        tree[n] = tree[2 * n] + tree[2 * n + 1];
    }
}

long long int count(int n, int l, int r, int cl, int cr) {
    if (l == cl && r == cr)
        return tree[n];
    else if (l > cr || r < cl)
        return 0;
    int m = (l + r) / 2;
    if (cl > m)
        return count(2 * n + 1, m + 1, r, cl, cr);
    else if (cr < m)
        return count(2 * n, l, m, cl, cr);
    else
        return count(2 * n, l, m, cl, m) +
               count(2 * n + 1, m + 1, r, m + 1, cr);
}
int main() {
    int n, m, l, r;
    while (~scanf("%d%d", &n, &m)) {
        set_tree(1, 1, n);
        while (m-- && scanf("%d%d", &l, &r)) {
            printf("%lld\n", count(1, 1, n, l, r));
        }
    }
}
