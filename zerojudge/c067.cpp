#include <iostream>
using namespace std;

const int maxn = 50;
int n, h[maxn + 5];

int main() {
    for (int t = 1;; t++) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += h[i];
        }

        int avg = sum / n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > avg) {
                ans += h[i] - avg;
            }
        }

        cout << "Set #" << t << endl;
        cout << "The minimum number of moves is " << ans << "." << endl << endl;
    }
}
