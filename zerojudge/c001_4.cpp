#include <stdio.h>
#include <string.h>
#define MAX 200
char map[MAX][MAX];
typedef struct nodetype {
    int x, y, t;
};
nodetype line[MAX * MAX];
int top = 1;
void add(int x, int y, int t) {
    if (map[x][y] != '#') line[top++] = {x, y, t};
}
int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        memset(line, 0, sizeof(line));
        top = 1;
        gets(map[0]);
        // input------------------------------------------------------
        for (int i = 0; i < N; i++) gets(map[i]);
        // find K --------------------------------
        int l = strlen(map[0]);
        for (int i = 0; i < l; i++) {
            bool find = 0;
            for (int j = 0; j < l; j++)
                if (map[i][j] == 'K') {
                    line[0] = {i, j, 0};
                    find = 1;
                    break;
                }
            if (find == 1) break;
        }
        // BFS--------------------------------------------------------
        int Ans = 0;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < top; i++) {
            if (map[line[i].x][line[i].y] == '@') {
                Ans = line[i].t;
                break;
            }
            map[line[i].x][line[i].y] = '#';
            for (int j = 0; j < 4; j++)
                add(line[i].x + dx[j], line[i].y + dy[j], line[i].t + 1);
        }
        // output-----------------------------------------------------
        if (!Ans)
            printf("= =\"\n");
        else
            printf("%d\n", Ans);
    }
}
