#include <iostream>

using namespace std;

int main() {
    long long int in0;
    while (cin >> in0) {
        if (in0 == 0) {
            cout << 0;
        }
        while (in0 % 10 == 0 && in0 > 0) {
            in0 /= 10;
        }
        while (in0) {
            cout << in0 % 10;
            in0 /= 10;
        }
        cout << endl;
    }
}
