#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
    int in0;

    while (cin >> in0) {
        int sum = 0;

        for (int i = 1; i <= in0 / 2; i++)
            if (in0 % i == 0) {
                sum += i;
            }

        if (sum == in0) {
            cout << "完全數\n";
        } else {
            cout << (sum > in0 ? "盈數\n" : "虧數\n");
        }
    }

    return 0;
}
