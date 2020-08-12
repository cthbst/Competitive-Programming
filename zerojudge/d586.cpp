#include <iostream>
using namespace std;

int main() {
    char N_C[] = "mjqhofawcpnsexdkvgtzblryui";
    char C_N[] = "uzrmatifxopnhwvbslekycqjgd";

    int in0 = 0;
    cin >> in0;
    while (in0--) {
        int sum = 0;
        int in1 = 0;
        cin >> in1;
        while (in1--) {
            char input[3];
            cin >> input;

            if ((int)(input[0] - 'a') < 0) {  //輸入為數字
                int k = (int)(input[0] - '0');
                if ((int)(input[1] - '0') >= 0) {
                    k *= 10;
                    k += (int)(input[1] - '0');
                }
                cout << N_C[k - 1];
            } else {
                for (int i = 0; i < 26; i++) {
                    if (C_N[i] == input[0]) {
                        sum += (i + 1);
                        break;
                    }
                }
            }
        }
        if (sum != 0) cout << sum;
        cout << endl;
    }
}
