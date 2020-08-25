#include <bits/stdc++.h>
using namespace std;

int main() {
    // 輸入 a, b, c
    long long a, b, c;
    cin >> a >> b >> c;

    // 排序 a, b, c
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    cout << a << ' ' << b << ' ' << c << '\n';

    // 按照題目要求輸出屬於甚麼三角形
    if (a + b <= c) {  // 無法形成三角形
        cout << "No" << '\n';
    } else if (a * a + b * b < c * c) {  // 鈍角三角形
        cout << "Obtuse" << '\n';
    } else if (a * a + b * b == c * c) {  // 直角三角形
        cout << "Right" << '\n';
    } else if (a * a + b * b > c * c) {  // 銳角三角形
        cout << "Acute" << '\n';
    }
}
