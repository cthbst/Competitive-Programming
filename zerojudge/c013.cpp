#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    cin >> in0;
    while (in0--) {
        int in1, in2;

        cin >> in1 >> in2;
        while (in2--) {
            for (int i = 1; i <= in1; i++) {
                for (int i1 = 1; i1 <= i; i1++) {
                    cout << i;
                }
                cout << endl;
            }
            for (int i = in1 - 1; i > 0; i--) {
                for (int i1 = 1; i1 <= i; i1++) {
                    cout << i;
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
