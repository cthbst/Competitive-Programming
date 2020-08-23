#include <iostream>
#include <map>
using namespace std;

int main() {
    long long ans;
    map<long long, int> mp;
    mp[1] = 1;
    for (int i = 1; i <= 1500; i++) {
        auto it = mp.begin();
        pair<long long, int> p = *mp.begin();
        long long x = p.first;
        ans = x;
        mp[2 * x] = 1;
        mp[3 * x] = 1;
        mp[5 * x] = 1;
        mp.erase(it);
    }
    cout << "The 1500'th ugly number is " << ans << "." << '\n';
    return 0;
}
