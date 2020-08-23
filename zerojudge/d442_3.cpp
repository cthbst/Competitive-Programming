#include <iostream>
using namespace std;

int next(int x) {
    if (x == 0) return 0;
    return next(x / 10) + (x % 10) * (x % 10);
}

int isHappy(int x) {
    while (1) {
        x = next(x);
        if (x == 1) return 1;
        if (x == 4) return 0;
    }
}

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int x;
        cin >> x;
        cout << "Case #" << cs << ": " << x << " ";
        if (isHappy(x) == 1) {
            cout << "is a Happy number.\n";
        } else {
            cout << "is an Unhappy number.\n";
        }
    }
    return 0;
}
