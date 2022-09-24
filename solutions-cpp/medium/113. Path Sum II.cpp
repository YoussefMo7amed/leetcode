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
    vector<vector<int>> ans;
    void solve(TreeNode *root, int target, vector<int> &v, int cur) {
        if (!(root->left) && !(root->right)) {
            if (cur + root->val == target) {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
        }
        cur += root->val;
        v.push_back(root->val);
        if (root->left) solve(root->left, target, v, cur);
        if (root->right) solve(root->right, target, v, cur);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if(!root)
            return ans;
        vector<int> v;
        solve(root, targetSum, v, 0);
        return ans;
    }
};