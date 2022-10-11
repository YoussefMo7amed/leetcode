
class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        return depth(root);
    }
    int depth(TreeNode *root) {
        if (!root) return INT_MAX;
        if ((!root->left) && !(root->right)) return 1;
        return min(depth(root->left), depth(root->right)) + 1;
    }
};