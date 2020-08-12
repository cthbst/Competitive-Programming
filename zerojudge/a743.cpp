#include <iostream>
#include <map>
#include <string>
using namespace std;

char in[1000];

map<string, int> S;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string country;
        cin >> country;
        cin.getline(in, 1000);
        S[country]++;
    }

    for (auto x : S) {
        cout << x.first << " " << x.second << endl;
    }
}
