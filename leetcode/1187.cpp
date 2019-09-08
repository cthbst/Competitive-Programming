class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        
        const int INF = 10000;
        
        int n = a.size();
        int m = b.size();
        
        vector< vector<int> > dp(n, vector<int>(m,INF));
        vector<int> ans(n, INF);
        
        ans[0] = 0;
        for (int i=0; i<m; i++) dp[0][i] = 1;
        for (int i=1; i<n; i++){
            if (a[i-1] < a[i]) ans[i] = ans[i-1];
            for (int j=0; j<m; j++){
                if (b[j] < a[i]){
                    ans[i] = min(ans[i], dp[i-1][j]);
                }
            }
            
            int best = INF;
            for (int j=0; j<m; j++){
                if (a[i-1] < b[j]) dp[i][j] = ans[i-1] + 1;
                dp[i][j] = min(dp[i][j], best + 1);
                best = min(best, dp[i-1][j]);
            }
        }
        
        int result = ans[n-1];
        for (int j=0; j<m; j++) result = min(result, dp[n-1][j]);
        if (result == INF) return -1;
        return result;
    }
};
