#include <iostream>
using namespace std;
int main(void) {
    int in[3];

    while (cin >> in[0] >> in[1] >> in[2]) {
        int S = (in[0] + in[1] + in[2]) / 2;
        cout << S * (S - in[0]) * (S - in[1]) * (S - in[2]) << endl;
    }
    return 0;
}
