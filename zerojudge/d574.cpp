#include <iostream>
#include <sstream>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    for (int n; cin >> n;) {
        stringstream ss;
        string s;
        cin >> s;
        s.push_back('$');
        for (int i = 1, cnt = 1; i <= n; i++) {
            if (s[i] != s[i - 1]) {
                ss << cnt << s[i - 1];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        s.pop_back();
        string ans = ss.str();
        if (ans.size() < s.size())
            cout << ans << '\n';
        else
            cout << s << '\n';
    }
}
