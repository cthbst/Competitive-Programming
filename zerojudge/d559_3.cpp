#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in1;
    while (cin >> in1) {
        cout << "\'C\' can use printf(\"%d\",n); to show integer like " << in1
             << endl;
    }
    return EXIT_SUCCESS;
}
