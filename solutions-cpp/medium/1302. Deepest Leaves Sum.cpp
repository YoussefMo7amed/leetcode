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
   private:
    int ans = 0;
    int deepest = 0;

   public:
    int deepestLeavesSum(TreeNode *root) {
        deepest = height(root);
        traves(root, 1);
        return ans;
    }
    int height(TreeNode *root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void traves(TreeNode *root, int currentHeight) {
        if(!root) return;
        if (currentHeight == deepest) {
            ans += root->val;
            return;
        }
        traves(root->left, currentHeight + 1);
        traves(root->right, currentHeight + 1);
    }
};