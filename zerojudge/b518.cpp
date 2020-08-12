#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int n, fa[maxn], tin[maxn];

int main() {
    int T;
    cin >> T;

    while (T-- && cin >> n) {
        memset(fa, -1, sizeof(fa));
        memset(tin, -1, sizeof(tin));
        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d,%d", &a, &b);
            if (tin[a] == -1) tin[a] = 0;
            if (tin[b] == -1) tin[b] = 0;
            fa[a] = b;
            tin[b]++;
        }
        for (int i = 0; i < 90; i++)
            if (tin[i] == 0) {
                if (fa[i] == 99 || fa[fa[i]] == 99)
                    printf("%d:N\n", i);
                else {
                    printf("%d:{%d", i, fa[i]);
                    int w = fa[fa[i]];
                    while (fa[w] != 99) printf(",%d", w), w = fa[w];
                    puts("}");
                }
            }
        puts("");
    }
}
