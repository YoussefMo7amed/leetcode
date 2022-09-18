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
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        int left = h(root->left);
        int right = h(root->right);
        return max({left + right, diameterOfBinaryTree(root->left),
                    diameterOfBinaryTree(root->right)});
    }
    int h(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(h(root->left), h(root->right));
    }
};
