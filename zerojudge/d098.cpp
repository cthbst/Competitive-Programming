#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool is_number(const string &s) {
    for (int i = 0; s[i]; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

int eval(const string &s) {
    if (is_number(s)) {
        return stoi(s);
    } else {
        return 0;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int sum = 0;
        for (string x; ss >> x;) {
            sum += eval(x);
        }
        cout << sum << '\n';
    }
}
