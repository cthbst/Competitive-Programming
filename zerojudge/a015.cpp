#include <iostream>
using namespace std;

int main() {
    const int maxn = 100;
    int n, m;
    int A[maxn][maxn];

    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
}
