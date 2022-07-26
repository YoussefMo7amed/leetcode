class Solution {
   public:
    int kthSmallest(TreeNode *root, int k) {
        set<int> s;
        traverse(root, s);
        return *next(s.begin(), k - 1);
    }
    void traverse(TreeNode *root, set<int> &s) {
        if (!root) return;
        s.insert(root->val);
        traverse(root->left, s);
        traverse(root->right, s);
    }
};
=========
class Solution {
   public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> v;
        // in-order Traversal
        traversal(root, v);
        return v[k - 1];
    }
    void traversal(TreeNode *root, vector<int> &s) {
        if (!root) return;
        traversal(root->left, s);
        s.push_back(root->val);
        traversal(root->right, s);
    }
};
