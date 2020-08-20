#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> cnt;
    for (int x; cin >> x;) {
        cnt[x]++;
    }
    for (pair<int, int> p : cnt) {
        if (p.second % 3 != 0) {
            cout << p.first << '\n';
            break;
        }
    }
    return 0;
}
