/* APCS 2016 March problem A */

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 宣告要數入的變數
    int n;
    int a[102];

    // 輸入n，接著用 for 迴圈輸入 a[0] ... a[n-1]
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 將 a[0] ... a[n-1] 由小到大排序完後輸出
    // a[n-1] 後面要輸出換行，不能輸出空白
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i < n - 1 ? ' ' : '\n');
    }

    // fail 紀錄小於60分中最大的數字，如果是 -1 表示沒有找到
    int fail = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < 60) {
            if (a[i] > fail) {  // 發現更大的
                fail = a[i];
            }
        }
    }
    if (fail == -1) {
        cout << "best case" << '\n';
    } else {
        cout << fail << '\n';
    }

    // pass 紀錄大於等於60分中最大的數字，如果是 101 表示沒有找到
    int pass = 101;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 60) {
            if (a[i] < pass) {  // 發現更小的
                pass = a[i];
            }
        }
    }
    if (pass == 101) {
        cout << "worst case" << '\n';
    } else {
        cout << pass << '\n';
    }
}
