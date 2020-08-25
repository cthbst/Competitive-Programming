#include <bits/stdc++.h>
using namespace std;

int main() {
    // 輸入 X
    int X;
    cin >> X;

    // A 是偶數位的總和, B 是奇數位的總和
    int A = 0, B = 0;
    while (X > 0) {
        A += X % 10;
        B += (X / 10) % 10;
        X /= 100;
    }

    // 輸出 A 和 B 的差
    cout << abs(A - B) << '\n';
}
