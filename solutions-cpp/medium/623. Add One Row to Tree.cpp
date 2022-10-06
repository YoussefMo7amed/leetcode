
class Solution {
   public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newNode = new TreeNode(val, root, NULL);
            return newNode;
        }
        restructure(root, val, depth, 1);
        return root;
    }
    void restructure(TreeNode *root, int val, int depth, int currentDepth) {
        if (!root) return;
        if (currentDepth == depth - 1) {
            TreeNode *left = new TreeNode(val, root->left, NULL);
            TreeNode *right = new TreeNode(val, NULL,root->right);
            root->left = left;
            root->right = right;
            return;
        }
        restructure(root->left, val, depth, currentDepth + 1);
        restructure(root->right, val, depth, currentDepth + 1);
    }
};