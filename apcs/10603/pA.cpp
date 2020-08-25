#include <bits/stdc++.h>
using namespace std;

int main() {
    // 輸入 X
    string X;
    cin >> X;

    // A 是偶數位的總和, B 是奇數位的總和
    // c-'0' 將字元轉成數字
    int A = 0, B = 0;
    for (int i = 0; i < X.size(); i += 2) {
        A += X[i] - '0';
    }
    for (int i = 1; i < X.size(); i += 2) {
        B += X[i] - '0';
    }

    // 輸出 A 和 B 的差
    cout << abs(A - B) << '\n';
}
