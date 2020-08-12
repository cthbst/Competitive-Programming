#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    cin >> in0;
    for (int i = 1; i <= in0; i++) {
        int in[3];

        cin >> in[0] >> in[1] >> in[2];

        if (in[0] - in[1] >= in[2] || in[1] - in[2] >= in[0] ||
            in[2] - in[0] >= in[1]) {
            cout << "Case " << i << ": Invalid\n";
        } else {
            if (in[0] == in[1] && in[1] == in[2]) {
                cout << "Case " << i << ": Equilateral\n";
            } else {
                if (in[0] == in[1] || in[1] == in[2] || in[2] == in[0]) {
                    cout << "Case " << i << ": Isosceles\n";
                } else {
                    cout << "Case " << i << ": Scalene\n";
                }
            }
        }
    }
    return 0;
}
