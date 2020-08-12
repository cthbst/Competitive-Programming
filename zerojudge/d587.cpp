#include <iostream>

using namespace std;

int main() {
    int in0;
    while (cin >> in0) {
        int count[4] = {0}, in1;

        while (in0--) {
            cin >> in1;
            count[in1]++;
        }

        for (int i = 1; i < 4; i++) {
            while (count[i]--) {
                cout << i << " ";
            }
        }
    }
}
