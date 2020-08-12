#include <math.h>

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    long long int in1, in2;
    while (cin >> in1 >> in2) {
        cout << (long long int)pow(in1, in2) << endl;
    }
    return EXIT_SUCCESS;
}
