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
    int goodNodes(TreeNode* root) {
        return search(root, root->val);
    }
    int search(TreeNode* root, int mx){
        if(!root)
            return 0;
        bool flag = root->val >= mx;
        mx = max(root->val, mx);

        return  flag + search(root->left, mx) + search(root->right, mx);
    }
};
