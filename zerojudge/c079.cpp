#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int in0, in1;

    while (cin >> in0 >> in1) {
        int sum = in0;

        while (in0 >= in1) {
            sum += in0 / in1;
            in0 = in0 / in1 + in0 % in1;
        }
        cout << sum << endl;
    }
    return 0;
}
