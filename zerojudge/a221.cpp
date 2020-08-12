#include <bits/stdc++.h>
using namespace std;

string s1, s2;

string noneSpace(string s) {
    string re;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != ' ') re += c;
    }
    return re;
}

void solve() {
    getline(cin, s1);
    getline(cin, s2);
    if (s1 == s2)
        cout << "Yes";
    else if (noneSpace(s1) == noneSpace(s2))
        cout << "Output Format Error";
    else
        cout << "Wrong Answer";
}

int main() {
    int T;
    cin >> T;
    getline(cin, s1);
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
        cout << endl;
    }
}
