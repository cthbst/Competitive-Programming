#include <cmath>
#include <iostream>

short prime(int in0) {
    short out = 0;

    for (int i = 2; i <= sqrt(in0); i++) {
        if (in0 % i == 0) {
            out = 1;
            break;
        }
    }
    if (in0 == 1) {
        out = 1;
    }

    return out;
}

using namespace std;

int main() {
    int in0, in1;

    while (cin >> in0 >> in1) {
        int out = 0;

        for (int i = in0; i <= in1; i++) {
            (prime(i) == 0 ? out++ : out = out);
        }

        cout << out << endl;
    }
}
