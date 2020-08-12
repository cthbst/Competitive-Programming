#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (b * b - 4 * a * c < 0)
            cout << "No real root\n";
        else if (b * b - 4 * a * c == 0)
            cout << "Two same roots x=" << -b / (2 * a) << endl;
        else
            cout << "Two different roots x1="
                 << (-b + sqrt(b * b - 4 * a * c)) / (2 * a)
                 << " , x2=" << (-b - sqrt(b * b - 4 * a * c)) / (2 * a)
                 << endl;
    }
    return 0;
}
