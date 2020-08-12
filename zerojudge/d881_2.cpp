#include <iostream>
using namespace std;

int main() {
    int d;

    while (cin >> d) {
        int sum = 0, ai = 1, delta = 1;

        for (int i = 1; i <= 50; i++) {
            sum += ai;
            ai += delta;
            delta += d;
        }

        cout << sum << endl;
    }
}
