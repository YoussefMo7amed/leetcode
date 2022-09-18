class Solution {
   public:
    bool isValidBST(TreeNode *root) {
        return compare(root, NULL, NULL);
    }
    bool compare(TreeNode *root, TreeNode* mn, TreeNode* mx) {
        if (!root)
            return true;

        if ((mn && mn->val >= root->val) || (mx && mx->val <= root->val))
            return false;

        return compare(root->left, mn, root) &&
               compare(root->right, root, mx);
    }
};
