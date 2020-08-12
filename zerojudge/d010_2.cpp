#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int in0;

    cin >> in0;
    for (int i = 0; i < in0; i++) {
        int in1, out = 0;

        cin >> in1;
        int in[6];
        for (int i1 = 0; i1 < in1; i1++)
            for (int i2 = 0; i2 < 6; i2++) {
                cin >> in[i2];
                if (i2 == 5 && in[i2] > out) {
                    out = in[i2];
                }
            }

        cout << out << endl;
    }
    return 0;
}
