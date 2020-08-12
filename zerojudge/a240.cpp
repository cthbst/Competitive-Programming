#include <iostream>
using namespace std;
int main(void) {
    short MOD16[16] = {0, 5, 8, 8, 2, 3, 5, 2, 9, 4, 1, 1, 7, 6, 4, 7};
    int in0;

    cin >> in0;
    int out[in0][2];

    for (int i = 0; i < in0; i++) {
        int in1 = 0;
        cin >> in1;

        out[i][0] = MOD16[(in1 % 16 - 1 >= 0 ? in1 % 16 - 1 : 15)];

        int SUM = 0;
        for (int i1 = 0; i1 < 16; i1++) {
            SUM += MOD16[i1] * (in1 / 16);
            if (i1 <= in1 % 16 - 1) {
                SUM += MOD16[i1];
            }
        }
        out[i][1] = SUM;
    }

    for (int i = 0; i < in0; i++) {
        cout << out[i][0] << " " << out[i][1] << endl;
    }

    return 0;
}
