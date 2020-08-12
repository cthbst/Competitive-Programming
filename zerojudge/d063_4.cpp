#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
Start:
    int a;
    cin >> a;
    if (a == 0) {
        return EXIT_SUCCESS;
    } else {
        int in1, in2, out = 0;
        cin >> in1;
        a -= 1;
        while (a--) {
            cin >> in2;
            if (in2 > in1) {
                out += (in2 - in1) * 20;
                in1 = in2;
            } else {
                out += (in1 - in2) * 10;
                in1 = in2;
            }
        }
        cout << out << endl;
    }

    goto Start;

    return EXIT_SUCCESS;
}
