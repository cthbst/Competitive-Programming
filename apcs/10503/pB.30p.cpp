/* APCS 2016 March problem B */

#include <bits/stdc++.h>
using namespace std;

// 宣告要輸入的變數
const int MAXN = 11;
int R, C, M;
int a[MAXN][MAXN];  // 矩陣

int main() {
    // 用兩層迴圈輸入矩陣，a[i][j] 表示第 i 列，第 j 欄
    cin >> R >> C >> M;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }
    if (M % 2 == 1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> a[i][C - 1 - j];
            }
            cout << '\n';
        }
    } else {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> a[i][j];
            }
            cout << '\n';
        }
    }
}
