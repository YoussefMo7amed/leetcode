struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
   public:
    bool contains(TreeNode *root) {
        if (!root) return false;
        if (!contains(root->left)) {
            root->left = NULL;
        }
        if (!contains(root->right)) {
            root->right = NULL;
        }
        return root->val == 1 || contains(root->right) || contains(root->left);
    }
    TreeNode *pruneTree(TreeNode *root) {
        if (root->val) {
            contains(root);
        } else {
            if (!contains(root)) root = NULL;
        }
        return root;
    }
};
