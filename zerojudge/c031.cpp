#include <iostream>

int pd0(int in0) {
    for (int i = 1; i < in0; i++)
        if ((i + 1) * i / 2 >= in0) {
            return i;
            break;
        }
}

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    while (cin >> in0) {
        if (in0 == 1) {
            cout << "TERM 1 IS 1/1\n";
        } else if (in0 == 2) {
            cout << "TERM 2 IS 1/2\n";
        } else if (pd0(in0) % 2 == 1) {
            cout << "TERM " << in0 << " IS "
                 << (pd0(in0) - (in0 - pd0(in0) * (pd0(in0) - 1) / 2) + 1)
                 << "/" << in0 - pd0(in0) * (pd0(in0) - 1) / 2 << endl;
        } else {
            cout << "TERM " << in0 << " IS "
                 << in0 - pd0(in0) * (pd0(in0) - 1) / 2 << "/"
                 << (pd0(in0) - (in0 - pd0(in0) * (pd0(in0) - 1) / 2) + 1)
                 << endl;
        }
    }
    return 0;
}
