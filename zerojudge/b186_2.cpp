#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    char A[4];
    int int_A = 0;
    cin >> int_A;

    A[0] = int_A / 1000;
    A[1] = int_A / 100 % 10;
    A[2] = int_A / 10 % 10;
    A[3] = int_A % 10;

    int in0;
    cin >> in0;

    short answer[in0][2];
    for (int i = 0; i < in0; i++) {
        int int_input = 0;
        char input[4];
        cin >> int_input;

        input[0] = int_input / 1000;
        input[1] = int_input / 100 % 10;
        input[2] = int_input / 10 % 10;
        input[3] = int_input % 10;

        // A
        answer[i][0] = 0;
        for (short i1 = 0; i1 < 4; i1++) {
            if (A[i1] == input[i1]) {
                answer[i][0]++;
            }
        }
        // B
        answer[i][1] = 0;
        for (short i1 = 0; i1 < 4; i1++) {
            for (short i2 = 0; i2 < 4; i2++) {
                if (A[i1] == input[i2]) {
                    answer[i][1]++;
                }
            }
        }
        answer[i][1] -= answer[i][0];
    }

    for (int i = 0; i < in0; i++) {
        cout << answer[i][0] << "A" << answer[i][1] << "B" << endl;
    }

    return 0;
}
