#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a = 10;
    while (a--) {
        int in1, in2, in3[29], a = 30, in4;
        cin >> in1 >> in2;
        while (a) {
            cin >> in4;
            in3[30 - a] = in4;
            a--;
        }
        if (in2 > in1) {
            int temp;
            temp = in1;
            in1 = in2;
            in2 = temp;
        }
        int ii = 0;
        while (a <= 29) {
            if (in3[a] == in1) ii -= 30;
            if (in3[a] > 0) ii++;
            if (ii >= 3) {
                cout << "N" << endl;
                a += 30;
            }
            a++;
        }

        if (ii < 2) cout << "Y" << endl;
    }

    return EXIT_SUCCESS;
}
