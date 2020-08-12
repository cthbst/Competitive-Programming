#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    cin >> in0;
    while (in0--) {
        int in1, in2;

        cin >> in1 >> in2;

        if (in2 > in1 || (in1 - in2) % 2 != 0) {
            cout << "impossible\n";
        } else {
            cout << in2 + (in1 - in2) / 2 << " " << (in1 - in2) / 2 << endl;
        }
    }

    return 0;
}
