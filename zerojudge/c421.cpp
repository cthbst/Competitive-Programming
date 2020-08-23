#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    map<int, int> mp;
    for (int x; cin >> x;) {
        if (x == 0) {
            break;
        } else if (x > 0) {
            mp[x]++;
        } else {
            if (mp.empty()) continue;
            int v;
            if (x == -1) {
                v = mp.begin()->first;
            } else {
                v = mp.rbegin()->first;
            }
            cout << v << ' ';
            mp[v]--;
            if (mp[v] == 0) mp.erase(v);
        }
    }
    return 0;
}
