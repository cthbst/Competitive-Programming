class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        if (a.size() <= 1) return false;
        map<long long, int> cnt;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (i - k - 1 >= 0) {
                int j = i - k - 1;
                cnt[a[j]]--;
                if (cnt[a[j]] == 0) {
                    cnt.erase(a[j]);
                }
            }
            if (cnt.size() > 0) {
                auto it = cnt.lower_bound(a[i]);
                if (it != cnt.end() && it->first - a[i] <= t) {
                    return true;
                }
                if (it != cnt.begin() && a[i] - prev(it)->first <= t) {
                    return true;
                }
            }
            cnt[a[i]]++;
        }
        return false;
    }
};
