#include <bits/stdc++.h>
using namespace std;

const int maxN = 10030;

int fa[maxN];

int root(int x) {
    if (fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}

int main() {
    int N, M, Q;

    cin >> N >> M >> Q;
    // init ------------------
    for (int i = 1; i <= N; i++) {
        fa[i] = i;
    }

    // build -----------------
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        a = root(a);
        b = root(b);
        fa[b] = a;
    }

    // query -----------------
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        if (root(a) == root(b))
            puts(":)");
        else
            puts(":(");
    }
}
