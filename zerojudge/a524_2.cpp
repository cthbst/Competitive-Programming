#include <stdio.h>
#include <string.h>

int N;

void out(int floor, int *a, bool *vis) {
    if (floor == N) {
        for (int i = 0; i < N; i++) printf("%d", a[i] + 1);
        printf("\n");
        return;
    } else {
        for (int i = N - 1; i >= 0; i--) {
            if (!vis[i]) {
                a[floor] = i;
                vis[i] = 1;
                out(floor + 1, a, vis);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    int a[10];
    bool vis[10];

    while (~scanf("%d", &N)) {
        memset(vis, 0, sizeof(vis));
        out(0, a, vis);
    }
}
