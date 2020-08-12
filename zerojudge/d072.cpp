#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a, b = 0;
    cin >> a;

    while (a--) {
        b++;
        int in1;
        cin >> in1;
        if (in1 % 400 == 0) {
            cout << "Case " << b << ": a leap year" << endl;
        } else if (in1 % 100 == 0) {
            cout << "Case " << b << ": a normal year" << endl;
        } else if (in1 % 4 == 0) {
            cout << "Case " << b << ": a leap year" << endl;
        } else {
            cout << "Case " << b << ": a normal year" << endl;
        }
    }
    return EXIT_SUCCESS;
}
