#include <stdio.h>
#include <string.h>

#define MAX 52
bool map[MAX][MAX];
int dx[5] = {0, 0, 0, 1, -1}, dy[5] = {0, 1, -1, 0, 0};
int main() {
    int T, M, N, K;
    scanf("%d", &T);
    while (T-- && scanf("%d%d%d", &M, &N, &K)) {
        memset(map, 0, sizeof(map));
        int in, count = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &in);
                if (in == 1)
                    for (int k = 0; k < 5; k++) {
                        if (i + dx[k] >= 0 && i + dx[k] < M && j + dy[k] >= 0 &&
                            j + dy[k] < N) {
                            if (!map[i + dx[k]][j + dy[k]]) {
                                map[i + dx[k]][j + dy[k]] = 1;
                                count++;
                            }
                        }
                    }
            }
        }
        printf("%d\n", M * N * K - 3 * count);
    }
}
