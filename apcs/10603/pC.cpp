#include <bits/stdc++.h>
using namespace std;

// 走一步的座標變化量，照順時針
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

const int MAXN = 51;
int n, dir, x, y;  // dir, x, y: 目前的方向, 目前在哪個 row, 目前在哪個 column
int a[MAXN][MAXN];

void walk(int L) {  // 走 L 部
    cout << a[x][y];
    for (int i = 0; i < L; i++) {
        x += dx[dir], y += dy[dir];
        cout << a[x][y];
    }
}

int main() {
    // 輸入起始資訊
    cin >> n >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    x = n / 2, y = n / 2;  // 一開始在中心點
    cout << a[x][y];
    for (int L = 1; L <= n / 2; L++) {
        // 先走再轉 (跨越不層外框)
        x += dx[dir], y += dy[dir];
        dir = (dir + 1) % 4;
        walk(L);

        // 先轉再走 (同一層外框的不同條邊)
        dir = (dir + 1) % 4;
        x += dx[dir], y += dy[dir];
        walk(L);

        dir = (dir + 1) % 4;
        x += dx[dir], y += dy[dir];
        walk(L);

        dir = (dir + 1) % 4;
        x += dx[dir], y += dy[dir];
        walk(L);
    }
}
