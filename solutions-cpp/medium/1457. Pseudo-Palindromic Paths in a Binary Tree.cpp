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
    map<int, int> mp;
    int cnt = 0;
    bool isPalindrome() {
        int odd = 0;
        for (auto i : mp) {
            if (i.second & 1) {
                odd++;
            }
        }
        return odd <= 1;
    }
    int pseudoPalindromicPaths(TreeNode *root) {
        for (int i = 1; i <= 9; i++) {
            mp[i] = 0;
        }
        traverse(root);
        return cnt;
    }
    void traverse(TreeNode *root) {
        if (!root) return;
        if (!root->left && !root->right) {
            mp[root->val]++;
            if (isPalindrome()) cnt++;
            mp[root->val]--;
            return;
        }
        mp[root->val]++;
        traverse(root->left);
        traverse(root->right);
        mp[root->val]--;
    }
};