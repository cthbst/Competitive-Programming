#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int in;
    while (cin >> in) {
        if (in == 0)
            return 0;
        else if (in % 400 == 0)
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
