#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
    int subarraySum(const vector<int>& a, int k) {
        vector<int> prefix = {0};
        for (int x : a) {
            prefix.push_back(prefix.back() + x);
        }
        int ans = 0;
        map<int, int> cnt;
        for (int x : prefix) {
            ans += cnt[x - k];
            cnt[x]++;
        }
        return ans;
    }
};

int main() {
    vector<int> a = {1, 1, 1};
    int k = 2;
    Solution solution;
    int ans = solution.subarraySum(a, k);
    cout << ans << endl;
}
