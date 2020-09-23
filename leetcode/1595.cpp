int n, m;
int dp[1 << 12][1 << 12];
const int INF = 1e9;
vector<vector<int>> cost;

class Solution {
public:
    int dfs(int X, int Y) {
        if (X == 0 && Y == 0) return 0;
        if (dp[X][Y] != -1) return dp[X][Y];
        int ans = INF;
        for (int i = 0; i < n; i++) {
            if (X & (1 << i)) {
                for (int j = 0; j < m; j++) {
                    if (Y & (1 << j)) {
                        ans = min(ans,
                                  dfs(X ^ (1 << i), Y ^ (1 << j)) + cost[i][j]);
                    } else {
                        ans = min(ans, dfs(X ^ (1 << i), Y) + cost[i][j]);
                    }
                }
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            if (Y & (1 << j)) {
                for (int i = 0; i < n; i++) {
                    if (X & (1 << i)) {
                        ans = min(ans,
                                  dfs(X ^ (1 << i), Y ^ (1 << j)) + cost[i][j]);
                    } else {
                        ans = min(ans, dfs(X, Y ^ (1 << j)) + cost[i][j]);
                    }
                }
                break;
            }
        }
        // cout << X << ' ' << Y << ' ' << ans << endl;
        return dp[X][Y] = ans;
    }
    int connectTwoGroups(vector<vector<int>>& _cost) {
        cost = _cost;
        memset(dp, -1, sizeof(dp));
        n = cost.size();
        m = cost[0].size();
        int ans = dfs((1 << n) - 1, (1 << m) - 1);
        return ans;
    }
};
