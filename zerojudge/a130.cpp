#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int time = 1; time <= T; time++) {
        string name[10];
        int a[10];
        int maxa = 0;
        for (int i = 0; i < 10; i++) {
            cin >> name[i] >> a[i];
            if (a[i] > maxa) maxa = a[i];
        }
        cout << "Case #" << time << ":" << endl;
        for (int i = 0; i < 10; i++)
            if (a[i] == maxa) {
                cout << name[i] << endl;
            }
    }
}
