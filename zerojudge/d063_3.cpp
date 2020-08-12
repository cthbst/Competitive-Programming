#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a;
    cin >> a;
    while (a--) {
        int in1, out = 0;
        cin >> in1;
        if (in1 / 27 > 0) {
            out += in1 / 27;
            in1 = in1 % 27;
        }
        if (in1 / 9 > 0) {
            out += in1 / 9;
            in1 = in1 % 9;
        }
        if (in1 / 3 > 0) {
            out += in1 / 3;
            in1 = in1 % 3;
        }
        out += in1;
        cout << out << endl;
    }

    return EXIT_SUCCESS;
}
