
class Solution {
   public:
    set<int> s;
    bool findTarget(TreeNode *root, int k) {
        if (!root) return false;
        if (s.find(k - root->val) != s.end()) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};