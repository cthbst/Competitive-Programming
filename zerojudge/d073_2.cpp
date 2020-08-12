#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in;
    while (cin >> in) {
        cout << (in % 3 == 0 ? in / 3 : in / 3 + 1) << endl;
    }
    return EXIT_SUCCESS;
}
