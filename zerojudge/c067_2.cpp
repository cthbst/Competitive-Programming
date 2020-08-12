#include <iostream>

using namespace std;
int main() {
    int in0;
    for (int i = 1; cin >> in0; i++) {
        if (in0 == 0) {
            return 0;
        }

        long long int in[in0], sum = 0, ru;

        for (int i1 = 0; i1 < in0; i1++) {
            cin >> in[i1];
            sum += in[i1];
        }

        ru = sum / in0;
        sum = 0;

        for (int i2 = 0; i2 < in0; i2++)
            if (in[i2] < ru) {
                sum += ru - in[i2];
            }

        cout << "Set #" << i << "\nThe minimum number of moves is " << sum
             << ". \n";
    }
    return 0;
}
