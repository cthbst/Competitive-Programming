#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in1;
    while (cin >> in1) {
        cout << in1 / 12 * 50 + in1 % 12 * 5 << endl;
    }
    return EXIT_SUCCESS;
}
