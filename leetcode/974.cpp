#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
    int subarraysDivByK(vector<int>& a, int k) {
        vector<int> prefix = {0};
        for (int x : a) {
            prefix.push_back((prefix.back() + x) % k);
        }
        int ans = 0;
        map<int, int> cnt;
        for (int x : prefix) {
            ans += cnt[x];
            cnt[x]++;
        }
        return ans;
    }
};

int main() {
    vector<int> a = {1, 1, 1};
    int k = 2;
    Solution solution;
    int ans = solution.subarraysDivByK(a, k);
    cout << ans << endl;
}
