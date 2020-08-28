#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int a[4];
            for (int j = 0; j < 4; j++) {
                cin >> a[j];
            }
            char ans;
            if (a[0] == 0 && a[1] == 1 && a[2] == 0 && a[3] == 1) {
                ans = 'A';
            } else if (a[0] == 0 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
                ans = 'B';
            } else if (a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 0) {
                ans = 'C';
            } else if (a[0] == 1 && a[1] == 1 && a[2] == 0 && a[3] == 1) {
                ans = 'D';
            } else if (a[0] == 1 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
                ans = 'E';
            } else if (a[0] == 1 && a[1] == 1 && a[2] == 0 && a[3] == 0) {
                ans = 'F';
            }
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
