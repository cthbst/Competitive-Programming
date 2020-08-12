#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in;
    while (cin >> in) {
        cout << (in <= 25 ? 25 - in : 85 - in) << endl;
    }
    return EXIT_SUCCESS;
}
