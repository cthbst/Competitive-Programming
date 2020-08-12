#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int out = 1;

        if (n == 0) {
            out = 0;
        }
        while (n) {
            out *= n % 10;
            n /= 10;
        }
        cout << out << endl;
    }
}
