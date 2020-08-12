#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in1;
    cin >> in1;
    while (in1--) {
        int in2, in3;
        cin >> in2 >> in3;
        cout << (in2 + in3) * 2 << endl;
    }
    return EXIT_SUCCESS;
}
