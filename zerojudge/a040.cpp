#include <iostream>

using namespace std;

int pow(int in0, int in1) {
    int out = 1;
    while (in1--) {
        out *= in0;
    }

    return out;
}

int main() {
    int in[2];

    while (cin >> in[0] >> in[1]) {
        int count = 0;
        for (int i = in[0]; i <= in[1]; i++) {
            //判斷位數
            int cpi = i, k = 1;  // k:位數
            while (cpi /= 10) {
                k++;
            }

            int sum = 0;
            cpi = i;
            while (cpi) {
                sum += pow(cpi % 10, k);
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
