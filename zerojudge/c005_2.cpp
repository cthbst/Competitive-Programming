#include <iostream>
using namespace std;
int main() {
    long long int a, b, c, d, e, n, m;
    long long int f = 0;
    while (cin >> a) {
        for (n = 1; n <= a; n++) {
            cin >> b;
            for (f = 0, m = 1; m <= b; m++) {
                cin >> c >> d >> e;
                f += (c * e);
            }
            cout << f << endl;
        }
    }
    return 0;
}
