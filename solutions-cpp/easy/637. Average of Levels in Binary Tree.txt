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
    vector<vector<double>> v;
    int h(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(h(root->left), h(root->right));
    }
    vector<double> averageOfLevels(TreeNode *root) {
        int n = h(root); // height of the tree, so i can know the number of levels
        v.resize(n);
        // adding the nodes that in the same level
        calc(root, 0);
        vector<double> ans;
        for (auto level : v) {
            double avg = 0;
            for (double node : level) avg += node;
            avg /= level.size();
            ans.push_back(avg);
        }
        return ans;
    }
    void calc(TreeNode *root, int level) {
        if (!root) return;
        v[level].push_back(root->val * 1.0); // i multiplied by 1.0 so int becomes double
        // going to next level
        calc(root->left, level + 1);
        calc(root->right, level + 1);
    }
};
