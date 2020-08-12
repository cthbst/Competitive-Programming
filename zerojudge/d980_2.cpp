#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    unsigned long long int in1, in2;

    while (cin >> in1 >> in2) {
        if (in1 == 0 && in2 == 0) {
            return 0;
        }

        if (in1 > in2) {
            cout << "Unfair";
        } else {
            cout << "Fair";
        }
        cout << endl;
    }

    return 0;
}
