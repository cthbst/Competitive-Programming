#include <iostream>
using namespace std;

int main() {
    unsigned int a, b, c;
    while (cin >> a >> b >> c) {
        if (a > b + c || c > a && a > b && a + b > c ||
            b > a && a > c && a + c > b)
            cout << "A\n";  //↑棄B保A                 ↑棄C保A
        else if (b > a + c || c > b && b > a && b + a > c ||
                 a > b && b > c && b + c > a)
            cout << "B\n";  //↑棄A保B                 ↑棄C保B
        else
            cout << "C\n";
    }
    return 0;
}
