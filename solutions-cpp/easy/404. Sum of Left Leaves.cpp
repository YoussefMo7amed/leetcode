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
    int sumOfLeftLeaves(TreeNode* root) {
        
        return left(root->left,1) + left(root->right,0);
    }
    int left(TreeNode* root, bool lft){
        if(root == NULL){
            return 0;
        }
        return (root->left == NULL && root->right == NULL && lft?root->val:0) + left(root->left,1)+ left(root->right,0);
    }
};