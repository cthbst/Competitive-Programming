#include <iostream>
using namespace std;
int main(void) {
    int in0;
    cin >> in0;
    int in[in0][3];
    string out[in0];

    for (int i = 0; i < in0; i++) {
        for (int i1 = 0; i1 < 3; i1++) {
            cin >> in[i][i1];
        }

        out[i] = (in[i][0] == in[i][1] || in[i][1] == in[i][2] ||
                          in[i][2] == in[i][0]
                      ? "NO"
                      : "YES");
    }

    for (int i = 0; i < in0; i++) {
        cout << out[i] << endl;
    }
    return 0;
}
