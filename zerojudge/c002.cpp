#include <iostream>

int f91(int in0) {
    if (in0 <= 100) {
        return f91(f91(in0 + 11));
    } else {
        return in0 - 10;
    }
}

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    while (cin >> in0 && in0 != 0) {
        cout << "f91(" << in0 << ") = " << f91(in0) << endl;
    }

    return 0;
}
