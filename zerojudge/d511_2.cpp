#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a = 5, out = 0;
    while (a--) {
        int in1, in2, in3, temp;
        cin >> in1 >> in2 >> in3;
        if (in1 < in2) {
            temp = in1;
            in1 = in2;
            in2 = temp;
        }
        if (in1 < in3) {
            temp = in1;
            in1 = in3;
            in3 = temp;
        }
        if (in2 + in3 > in1) out += 1;
    }
    cout << out << endl;
    return EXIT_SUCCESS;
}
