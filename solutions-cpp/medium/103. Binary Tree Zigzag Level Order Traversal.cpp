/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        levelByLevel(root, ans, 0);
        zigzag(ans);
        return ans;
    }
    void levelByLevel(TreeNode *root, vector<vector<int>> &ans,
                      int currentLevel) {
        if (!root) return;
        if (ans.size() < currentLevel + 1) ans.push_back({});
        ans[currentLevel].push_back(root->val);
        levelByLevel(root->left, ans, currentLevel + 1);
        levelByLevel(root->right, ans, currentLevel + 1);
    }
    void zigzag(vector<vector<int>> &ans) {
        for (int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
    }
};