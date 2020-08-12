#include <bits/stdc++.h>
using namespace std;

int fa[1000];
int cnt[1000];
bool cir[1000];

int root(int x) {
    if (fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}
void Union(int u, int v) {
    u = root(u), v = root(v);
    if (u == v)
        cir[u] = 1;
    else {
        fa[v] = u;
        cnt[u] += cnt[v];
        cnt[v] = 0;
    }
}
char G[40][40];

int encode(int x, int y) {
    return x * 30 + y;
}

int main() {
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        scanf("%s", G[i]);
    }
    for (int i = 0; i < 1000; i++) {
        fa[i] = i;
        cnt[i] = 1;
        cir[i] = 0;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
            if (G[i][j] == '.' && G[i][j] == G[i][j + 1])
                Union(encode(i, j), encode(i, j + 1));
        }
    }
    for (int i = 0; i < H - 1; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '.' && G[i][j] == G[i + 1][j])
                Union(encode(i, j), encode(i + 1, j));
        }
    }

    unsigned long long x = 0, y = 0, z = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int id = encode(i, j);
            if (fa[id] == id && cir[id] == 1) {
                x++;
                y += cnt[id];
                z *= (unsigned long long)cnt[id];
            }
        }
    }
    cout << x << " " << y << " " << z << endl;
}
