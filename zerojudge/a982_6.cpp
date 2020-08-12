#include <stdio.h>
#include <string.h>

int vis[2][7][7];
int v[2][30][2];
bool check(int n) {
    for (int i = 1; i <= 5; i++) {
        int r = 0, l = 0;
        for (int j = 1; j <= 5; j++) {
            r += vis[n][i][j];
            l += vis[n][j][i];
        }
        if (r == 5 || l == 5) return 1;
    }
    int t = 0, d = 0;
    for (int i = 1; i <= 5; i++) {
        d += vis[n][i][i];
        t += vis[n][i][6 - i];
    }
    if (t == 5 || d == 5) return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        memset(vis, 0, sizeof(vis));
        int in;
        for (int k = 0; k < 2; k++) {
            for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++) {
                    scanf("%d", &in);
                    v[k][in][0] = i, v[k][in][1] = j;
                }
            }
        }

        bool ok = 0;
        for (int i = 0; i < 25; i++) {
            scanf("%d", &in);

            vis[0][v[0][in][0]][v[0][in][1]] = 1;
            vis[1][v[1][in][0]][v[1][in][1]] = 1;

            if (ok == 0 && (check(0) == 1 || check(1) == 1)) {
                ok = 1;
                if (check(0) == 1 && check(1) == 0)
                    printf("1\n");
                else if (check(0) == 0 && check(1) == 1)
                    printf("2\n");
                else
                    printf("0\n");
            }
        }
    }
}
