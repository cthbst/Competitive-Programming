#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in1, in2, in3, temp;
    while (cin >> in1 >> in2 >> in3) {
        if (in2 > in1) {
            temp = in1;
            in1 = in2;
            in2 = temp;
        }
        if (in3 > in1) {
            temp = in1;
            in1 = in3;
            in3 = temp;
        }
        if (in1 * in1 == in2 * in2 + in3 * in3) {
            cout << "right triangle";
        } else {
            cout << (in1 * in1 > in2 * in2 + in3 * in3 ? "obtuse triangle"
                                                       : "acute triangle");
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
