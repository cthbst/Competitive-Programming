#include <iostream>
//#include <string.h>
using namespace std;

int f(int x) {
    int count = 0;

    int cpx = x;
    while (cpx / 2 > 0) {
        count++;
        cpx /= 2;
    }

    cpx = x;
    while (cpx / 5 > 0) {
        count++;
        cpx /= 5;
    }

    return count + 1;
}

int main() {
    int in0;
    cin >> in0;
    while (in0--) {
        int in1;
        cin >> in1;
        int sum = 0;
        while (in1) {
            sum += f(in1);
            in1 /= 10;
        }
        cout << sum - 1 << endl;
    }
}
