#include <iostream>

using namespace std;

int pow(int k, int n) {
    int out = k;

    while (--n) {
        out *= k;
    }
    return out;
}

int main() {
    int in0, in1;

    while (cin >> in0 >> in1) {
        short count = 0;

        for (int i = in0; i <= in1; i++) {
            short n = 0;  //位數

            int cpi = i;
            while (cpi) {
                n++;
                cpi /= 10;
            }
            int sum = 0;
            cpi = i;

            while (cpi) {
                sum += pow(cpi % 10, n);
                cpi /= 10;
            }
            if (sum == i) {
                cout << i << " ";
                count++;
            }
        }
        if (count == 0) {
            cout << "none";
        }
        cout << endl;
    }
}
