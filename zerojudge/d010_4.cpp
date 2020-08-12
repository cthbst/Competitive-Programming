#include <iostream>
using namespace std;
int main(void) {
    int in0;
    cin >> in0;
    while (in0--) {
        int in1, sum = 0, out = 0;
        cin >> in1;
        int in[in1 - 1];
        for (int i = 0; i < in1; i++) {
            cin >> in[i];
            sum += in[i];
            if (sum == 0) out++;
        }
        cout << out << endl;
    }
    return 0;
}
