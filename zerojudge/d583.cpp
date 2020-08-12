#include <iostream>

using namespace std;

int main() {
    int in0;

    while (cin >> in0) {
        for (int i = 0; i < in0; i++) {
            int in1;
            cin >> in1;
        }

        for (int i = 1; i <= in0; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
}
