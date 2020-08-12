#include <math.h>

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int in1, in2, out = 0;
    while (cin >> in1 >> in2) {
        int i = in1;
        for (i; i <= in2; i++) {
            if (i % 4 == 0) {
                if (i % 400 == 0)
                    out += 1;
                else if (i % 100 == 0)
                    out += 0;

                else
                    out += 1;
            }
        }
        cout << out << endl;
    }
    return EXIT_SUCCESS;
}
