#include <stdio.h>
#include <string.h>

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int maxN = 130;
char maze[maxN][maxN];

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (maze[nx][ny] == '-') {
            maze[nx][ny] = '+';
            dfs(nx, ny);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    memset(maze, 0, sizeof(maze));
    // input -----------------
    for (int i = 1; i <= N; i++) {
        scanf("%s", maze[i] + 1);
    }
    int px, py;
    scanf("%d%d", &px, &py);
    maze[px + 1][py + 1] = '+';
    // dfs -------------------
    dfs(px + 1, py + 1);

    // output ----------------
    for (int i = 1; i <= N; i++) {
        puts(maze[i] + 1);
    }
}
