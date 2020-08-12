#include <iostream>

using namespace std;

int main() {
    int in0, in1;

    while (cin >> in0 >> in1) {
        if ((in0 * 2 + in1) % 3 == 0)
            cout << "普通";
        else if ((in0 * 2 + in1) % 3 == 1)
            cout << "吉";
        else
            cout << "大吉";

        cout << endl;
    }
}
