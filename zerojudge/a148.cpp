#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    while (cin >> in0) {
        long long int in1, sum = 0;

        for (int i = 0; i < in0; i++) {
            cin >> in1;
            sum += in1;
        }

        cout << (sum <= in0 * 59 ? "yes" : "no") << endl;
    }

    return 0;
}
