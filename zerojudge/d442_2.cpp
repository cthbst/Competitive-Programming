#include <iostream>
#include <map>
using namespace std;

int next(int x) {
    if (x == 0) return 0;
    return next(x / 10) + (x % 10) * (x % 10);
}

bool isHappy(int x) {
    map<int, bool> used;
    while (x != 1) {
        if (used[x]) return false;
        used[x] = true;
        x = next(x);
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int x;
        cin >> x;
        cout << "Case #" << cs << ": " << x << " ";
        if (isHappy(x)) {
            cout << "is a Happy number.\n";
        } else {
            cout << "is an Unhappy number.\n";
        }
    }
    return 0;
}
