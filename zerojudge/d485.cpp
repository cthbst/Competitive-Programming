#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in1, in2;
    while (cin >> in1 >> in2) {
        cout << (in1 % 2 != 0 && in2 % 2 != 0 ? (in2 - in1) / 2
                                              : (in2 - in1) / 2 + 1)
             << endl;
    }
    return EXIT_SUCCESS;
}
