#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in1 = 0, out = 0;

    cin >> in1;

    if (in1 >= 40) {
        out = 100;
        in1 -= in1;
    }
    //--------------------------------------
    if (in1 >= 10) {
        out += 60;
        in1 -= 10;
    } else {
        out += in1 * 6;
        in1 -= in1;
    }
    //--------------------------------------
    if (in1 >= 10) {
        out += 20;
        in1 -= 10;
    } else {
        out = out + in1 * 2;
        in1 -= in1;
    }
    //--------------------------------------
    out += in1;
    cout << out << endl;
}
