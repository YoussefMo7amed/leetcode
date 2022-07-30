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
class BSTIterator {
   public:
    queue<int> q;

    void init(TreeNode *root) {
        if (!root) return;
        init(root->left);
        q.push(root->val);
        init(root->right);
    }
    BSTIterator(TreeNode *root) {
        q.push(-1);
        init(root);
    }

    int next() {
        q.pop();
        return q.front();
    }

    bool hasNext() {
        return !(q.size() <= 1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
