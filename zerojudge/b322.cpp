#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

#define maxN 32767

int N, M;
vector<int> E[maxN];

int tin[maxN], tout[maxN], t;
int per[maxN][16];
int add[maxN];

int log2(int x) {
    int re = 0;
    while (x) x /= 2, re++;
    return re;
}

void set_t(int x, int fa) {
    tin[x] = t++;

    per[x][0] = fa;

    for (int i = 1; (1 << i) < N / 2; i++) {
        per[x][i] = per[per[x][i - 1]][i - 1];
    }

    for (int i = E[x].size() - 1; i >= 0; i--) {
        if (E[x][i] == fa) continue;
        set_t(E[x][i], x);
    }

    tout[x] = t++;
}

bool is_fa(int fa, int son) {
    return tin[fa] <= tin[son] && tout[fa] >= tout[son];
}

int LCA(int a, int b) {
    if (is_fa(a, b)) return a;
    if (is_fa(b, a)) return b;

    for (int i = log2(N / 2); i >= 0; i--)
        if (!is_fa(per[a][i], b)) a = per[a][i];

    return per[a][0];
}

void CON(int x, int px) {
    for (int i = E[x].size() - 1; i >= 0; i--) {
        if (E[x][i] == px) continue;
        CON(E[x][i], x);
        add[x] += add[E[x][i]];
    }
}
int main() {
    while (~scanf("%d%d", &N, &M)) {
        // input -------------
        for (int i = 0; i < N; i++) E[i].clear();
        for (int i = 0, a, b; i < N - 1; i++) {
            scanf("%d%d", &a, &b);
            E[a].push_back(b);
            E[b].push_back(a);
        }
        t = 0, set_t(0, 0);

        // query -------------
        memset(add, 0, sizeof(add));
        for (int i = 0, a, b, k; i < M; i++) {
            scanf("%d%d%d", &a, &b, &k);
            int m = LCA(a, b);
            add[a] += k, add[b] += k, add[m] -= k;
            if (per[m][0] != m) add[per[m][0]] -= k;
        }
        // output ------------
        CON(0, 0);
        for (int i = 0; i < N; i++) printf("%d ", add[i]);
        printf("\n");
    }
}
