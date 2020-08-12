#include <stdio.h>

#include <queue>
using namespace std;

struct str {
    int type, val;
};
struct str2 {
    int x, y;
};

str state[15][15];

int R, C;

int near(str2 a) {
    int r = a.x, c = a.y;
    if ((r == 1 || r == R) && (c == 1 || c == C)) return 2;
    if ((r == 1 || r == R) || (c == 1 || c == C)) return 3;
    return 4;
}

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int main() {
    int T;

    while (scanf("%d%d%d", &R, &C, &T) && !(R == 0 && C == 0 && T == 0)) {
        // init --------------
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) state[i][j] = (str){-1, 1};
        // solve -------------
        for (int i = 1, r, c; i <= T; i++) {
            scanf("%d%d", &r, &c);

            state[r][c].type = i & 1;
            state[r][c].val++;

            queue<str2> que;
            que.push((str2){r, c});

            while (!que.empty()) {
                str2 w = que.front();
                que.pop();

                if (state[w.x][w.y].val <= near(w)) continue;
                state[w.x][w.y].val -= near(w);

                for (int i = 0; i < 4; i++) {
                    int nx = w.x + dx[i], ny = w.y + dy[i];
                    if (1 <= nx && nx <= R && 1 <= ny && ny <= C) {
                        state[nx][ny].type = state[w.x][w.y].type;
                        state[nx][ny].val++;
                        que.push((str2){nx, ny});
                    }
                }

                int boo = state[1][1].type;
                for (int i = 1; i <= R && boo != -1; i++) {
                    for (int j = 1; j <= C && boo != -1; j++) {
                        if (state[i][j].type != boo) boo = -1;
                    }
                }
                if (boo != -1) break;
            }
        }
        // output ------------
        int A = 0, B = 0;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (state[i][j].type == 1) A++;
                if (state[i][j].type == 0) B++;
            }
        }

        printf("%d %d ", A, B);
        if (A == R * C)
            puts("GREEN");
        else if (B == R * C)
            puts("BLUE");
        else
            puts("processing");
    }
}
