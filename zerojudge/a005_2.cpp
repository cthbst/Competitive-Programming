#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a = 0;
    cin >> a;
    while (a--) {
        int in1 = 0, in2 = 0, in3 = 0, in4 = 0, out = 0;
        cin >> in1 >> in2 >> in3 >> in4;
        if ((in4 - in3) == (in2 - in1))
            out = in4 + in2 - in1;
        else if ((in4 / in3) == (in2 / in1))
            out = in4 * (in4 / in3);
        else
            cout << "HI";

        cout << in1 << " " << in2 << " " << in3 << " " << in4 << " " << out
             << "\n";
    }
}
