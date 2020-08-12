#include <iostream>

using namespace std;
int main(int argc, char* argv[]) {
    int in0;

    while (cin >> in0) {
        int sum = 2, ru = 1;

        for (int i = 1; i < 50; i++) {
            sum += ru, ru = 1 + (2 + i * in0) * (i + 1) / 2;
        }
        cout << sum << endl;
    }

    return 0;
}
