#include <iostream>

using namespace std;

int main() {
    short in0;  //次數
    int in[4];  //每次輸入的四個值

    cin >> in0;
    while (in0--) {
        for (short i = 0; i < 4; i++) cin >> in[i];

        for (short i = 0; i < 4; i++) {
            cout << in[i] << " ";
        }

        if (in[0] + in[2] == in[1] * 2)  //等差數列
            cout << in[3] * 2 - in[2];
        else  //等比數列
            cout << in[3] * in[3] / in[2];

        cout << endl;
    }
}
