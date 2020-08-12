#include <stdio.h>
#include <string.h>

int in[6][7], find;

int walk(int floor, int *k, bool *v) {
    if (find)
        ;
    else if (floor == 6) {
        int ok = 1, count;
        for (int i = 0; i < 6; i++ && ok, count = 0) {
            for (int j = 0; j < 6; j++)
                if (in[i][j] - 1 == k[j]) count++;
            if (count != in[i][6]) ok = 0;
        }
        if (ok) {
            find = 1;
            for (int i = 0; i < 6; i++) printf("%d ", k[i] + 1);
            printf("\n");
        }
    } else {
        for (int i = 0; i < 6; i++)
            if (!v[i]) {
                v[i] = 1;
                k[floor] = i;
                walk(floor + 1, k, v);
                v[i] = 0;
            }
    }
}

int main() {
    while (~scanf("%d%d%d%d%d%d%d", &in[0][0], &in[0][1], &in[0][2], &in[0][3],
                  &in[0][4], &in[0][5], &in[0][6])) {
        for (int i = 1; i < 6; i++)
            for (int j = 0; j < 7; j++) scanf("%d", &in[i][j]);

        find = 0;
        int kk[6];
        memset(kk, 0, sizeof(kk));
        bool vis[7];
        memset(vis, 0, sizeof(vis));
        walk(0, kk, vis);
    }
}
