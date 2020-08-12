#include <iostream>

int n;
using namespace std;

void change0(int a[]) {
    int i, j, temp;
    for (i = 1; i < n; i++)
        for (j = 0; j < (n - i); j++)
            if (a[j] % 10 > a[j + 1] % 10) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}
void change1(int a[]) {
    int i, j, temp;
    for (i = 1; i < n; i++)
        for (j = 0; j < (n - i); j++)
            if (a[j] % 10 == a[j + 1] % 10 && a[j] / 10 < a[j + 1] / 10) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int main() {
    while (cin >> n) {
        int a[n];
        for (int i = 0; i < n && cin >> a[i]; i++)
            ;
        change0(a);
        change1(a);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
