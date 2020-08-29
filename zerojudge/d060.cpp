#include <iostream>
using namespace std;

int main() {
    int m;
    while (cin >> m) {
        if (m <= 25) {
            cout << 25 - m << '\n';
        } else {
            cout << 85 - m << '\n';
        }
    }
    return 0;
}
