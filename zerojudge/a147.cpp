#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in0;
    while (cin >> in0) {
        if (in0 == 0) return EXIT_SUCCESS;
        for (int i = 1; i < in0; i++) {
            // cout << (i%7==0?" ": "i" ) ;
            if (i % 7 != 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
