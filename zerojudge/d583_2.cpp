#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in1, in2;
    while (cin >> in1) {
        int cpin1;
        cpin1 = in1;
        while (cpin1--) {
            cin >> in2;
        }

        for (cpin1 = 1; cpin1 <= in1; cpin1++) {
            cout << cpin1 << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
