#include <math.h>

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int in1, in2, i, out;
    while (cin >> in1 >> in2) {
        for (i = 1; i <= in1 && i <= in2; i++) {
            if (in1 % i == 0 && in2 % i == 0) {
                out = i;
            }
        }
        cout << out << endl;
    }
    return EXIT_SUCCESS;
}
