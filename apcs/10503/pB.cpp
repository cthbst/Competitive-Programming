/* APCS 2016 March problem B */

#include <bits/stdc++.h>
using namespace std;

// 宣告要輸入的變數
const int MAXN = 11;
int R, C, M;
int a[MAXN][MAXN];  // 矩陣
int op[MAXN];       // 操作, 0 旋轉, 1 翻轉

int main() {
    // 用兩層迴圈輸入矩陣，a[i][j] 表示第 i 列，第 j 欄
    cin >> R >> C >> M;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> op[i];
    }

    for (int k = M - 1; k >= 0; k--) {  // 回復操作，由後往前
        // 先將本來的矩陣複製一份
        int tmp[MAXN][MAXN];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                tmp[i][j] = a[i][j];
            }
        }

        if (op[k] == 1) {
            // (i,j) 換到 (R-1-i,j)
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    a[R - 1 - i][j] = tmp[i][j];
                }
            }
        } else {  // op[k] == 0;
            // (i,j) 換到 (R-1-i,j)
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    a[C - 1 - j][i] = tmp[i][j];
                }
            }
            swap(R, C);  // R,C 也要交換
        }
    }

    // 輸出最一開始的矩陣
    cout << R << ' ' << C << '\n';
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << a[i][j] << (j < C - 1 ? ' ' : '\n');
        }
    }
}
