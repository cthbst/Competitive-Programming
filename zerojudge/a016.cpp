#include <stdio.h>
#include <string.h>

int S[10][10];
bool vis[10];

bool all_vis() {
    bool ok = 1;
    for (int i = 1; i <= 9 && ok; i++)
        if (!vis[i]) ok = 0;
    return ok;
}
int main() {
    while (~scanf("%d", &S[1][1])) {
        // input----------------------------------
        for (int i = 2; i <= 9; i++) scanf("%d", &S[1][i]);
        for (int i = 2; i <= 9; i++)
            for (int j = 1; j <= 9; j++) scanf("%d", &S[i][j]);
        // check----------------------------------
        bool ok = 1;
        //直的-------------------------
        if (ok) {
            for (int i = 1; i <= 9 && ok; i++) {
                memset(vis, 0, sizeof(vis));
                for (int j = 1; j <= 9; j++) {
                    vis[S[i][j]] = 1;
                }
                if (!all_vis()) ok = 0;
            }
        }
        //橫的-------------------------
        if (ok) {
            for (int i = 1; i <= 9 && ok; i++) {
                memset(vis, 0, sizeof(vis));
                for (int j = 1; j <= 9; j++) {
                    vis[S[j][i]] = 1;
                }
                if (!all_vis()) ok = 0;
            }
        }
        //方的-------------------------
        if (ok) {
            for (int bi = 2; bi <= 8; bi += 3) {
                for (int bj = 2; bj <= 8; bj += 3) {
                    memset(vis, 0, sizeof(vis));
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            vis[S[bi + i][bj + j]] = 1;
                        }
                    }
                    if (!all_vis()) ok = 0;
                }
            }
        }
        // output-------------------------------------------
        printf("%s\n", ok ? "yes" : "no");
    }
}
