#include <iostream>
using namespace std;
int main() {
    int a;
    while (cin >> a) {
        if (a % 400 == 0)
            cout << "閏年";

        else if (a % 100 == 0)
            cout << "平年";
        else if (a % 4 == 0)
            cout << "閏年";
        else
            cout << "平年";
        cout << endl;
    }

    return 0;
}
