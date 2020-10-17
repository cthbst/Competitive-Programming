// Copyright (C) Algo Seacow. 2020. All Rights Reserved.
#include <bits/stdc++.h>
using namespace std;

const int N = 60;

int R, C, k, m;
int grids[N][N][N], deg[N][N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    // init
    for (int t = 0; t < N; t++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grids[t][i][j] = -1;
            }
        }
    }

    // input
    cin >> R >> C >> k >> m;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> grids[0][i][j];
        }
    }

    // deg[i][j]
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            deg[i][j] = 0;
            deg[i][j] += (grids[0][i + 1][j] != -1);
            deg[i][j] += (grids[0][i - 1][j] != -1);
            deg[i][j] += (grids[0][i][j + 1] != -1);
            deg[i][j] += (grids[0][i][j - 1] != -1);
        }
    }

    // simulate
    for (int day = 1; day <= m; day++) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (grids[0][i][j] == -1) continue;
                grids[day][i][j] = grids[day - 1][i][j];
                grids[day][i][j] -= grids[day - 1][i][j] / k * deg[i][j];
                grids[day][i][j] += grids[day - 1][i + 1][j] / k;
                grids[day][i][j] += grids[day - 1][i - 1][j] / k;
                grids[day][i][j] += grids[day - 1][i][j + 1] / k;
                grids[day][i][j] += grids[day - 1][i][j - 1] / k;
            }
        }
    }

    // find ans
    int mi = 1e9, mx = -1e9;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (grids[0][i][j] == -1)
                continue;
            mi = min(mi, grids[m][i][j]);
            mx = max(mx, grids[m][i][j]);
        }
    }
    cout << mi << endl;
    cout << mx << endl;

    return 0;
}
