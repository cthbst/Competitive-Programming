#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    while (a--) {
        int in;
        cin >> in;
        if (in % 400 == 0)
            cout << "a leap year";
        else if (in % 100 == 0)
            cout << "a normal year";
        else if (in % 4 == 0)
            cout << "a leap year";
        else
            cout << "a normal year";
        cout << endl;
    }
    return 0;
}
