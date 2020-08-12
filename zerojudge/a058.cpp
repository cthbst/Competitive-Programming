#include <iostream>
using namespace std;
int main(void) {
    int in0, out[3] = {0};
    cin >> in0;
    while (in0--) {
        int in1;
        cin >> in1;
        out[in1 % 3]++;
    }
    for (short i = 0; i < 3; i++) {
        cout << out[i] << " ";
    }
    return 0;
}
