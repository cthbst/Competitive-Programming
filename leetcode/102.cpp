/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        deque<pair<TreeNode*, int>> que;
        que.push_back({root, 0});
        while (que.size() > 0) {
            TreeNode* u = que.front().first;
            int d = que.front().second;
            que.pop_front();
            if (ans.size() == d) ans.push_back({});
            ans[d].push_back(u->val);
            if (u->left != nullptr) {
                que.push_back({u->left, d + 1});
            }
            if (u->right != nullptr) {
                que.push_back({u->right, d + 1});
            }
        }
        return ans;
    }
};
