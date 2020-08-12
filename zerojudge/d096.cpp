#include <iostream>
using namespace std;

int main() {
    unsigned long long int k;
    while (cin >> k) {
        if (k == 1)
            cout << k << endl;
        else
            cout << (k * k + 2 * k - 5) / 2 * 3 << endl;
    }
}
