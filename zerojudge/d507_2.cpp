#include <cstdlib>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int in[3];

    while (cin >> in[0] >> in[1] >> in[2]) {
        int large = 0;

        for (int i = 0; i < 3; i++)
            if (in[i] > large) {
                large = in[i];
            }

        if (large * large * 2 ==
            in[0] * in[0] + in[1] * in[1] + in[2] * in[2]) {
            cout << "right triangle\n";
        } else if (large * large * 2 >
                   in[0] * in[0] + in[1] * in[1] + in[2] * in[2]) {
            cout << "obtuse triangle\n";
        } else {
            cout << "acute triangle\n";
        }
    }
    return EXIT_SUCCESS;
}
