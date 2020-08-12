#include <iostream>
#include <sstream>  // stringstream
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        long long sum = 0, x;
        while (ss >> x) {
            sum += x;
        }
        cout << sum << '\n';
    }
}
