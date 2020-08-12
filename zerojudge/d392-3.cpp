#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

char line[100000];
int main() {
    while (cin.getline(line, sizeof(line))) {
        stringstream s(line);
        long long sum = 0, x;
        while (s >> x) {
            sum += x;
        }
        cout << sum << '\n';
    }
}
