#include <iostream>

using namespace std;

int main() {
    int in0;
    while (cin >> in0) {
        char out[32] = {32};
        int count = 0;
        while (in0) {
            out[count] = in0 % 2 + 48;
            in0 /= 2;
            count++;
        }
        for (int i = 31; i >= 0; i--) {
            if (out[i] >= 48) {
                cout << out[i];
            }
        }
        cout << endl;
    }
}
