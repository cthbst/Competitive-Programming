#include <iostream>

using namespace std;

int main() {
    int in0;
    string A[10] = {
        "BNZ", "AMW", "KLY", "JVX", "HU", "GT", "FS", "ER", "DOQ", "CIP",
    };

    while (cin >> in0) {
        int sum = in0 % 10;
        in0 /= 10;
        for (short i = 1; i < 9; i++) {
            sum += (in0 % 10) * i;
            in0 /= 10;
        }

        // cout <<sum <<endl ;
        // cout <<(10-(sum%10))%10 <<endl ;

        cout << A[(10 - (sum % 10)) % 10] << endl;
    }
}
