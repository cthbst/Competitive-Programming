#include <iostream>
using namespace std;

int main() {
    unsigned long long n;
    while (cin >> n) {
        if (n == 1) {
            cout << n << endl;
        } else {
            cout << (n * n + 2 * n - 5) / 2 * 3 << endl;
        }
    }
    return 0;
}
