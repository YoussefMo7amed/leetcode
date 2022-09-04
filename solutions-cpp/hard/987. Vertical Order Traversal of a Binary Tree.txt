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
    // value, {direction, level}
    vector<pair<int, pair<int, int>>> nodes;

    static bool srt(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        if (a.second.first == b.second.first) {
            if (a.second.second == b.second.second) return a.first < b.first;
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        traverse(root, 0, 0);
        sort(nodes.begin(), nodes.end(), srt);
        int mn = nodes.front().second.first;  // first col
        int mx = nodes.back().second.first;   // last col
        vector<vector<int>> ans(1 + abs(mn) + mx);
        int indx = abs(mn);
        for (auto node : nodes) {
            ans[indx + node.second.first].push_back(node.first);
            // cout <<indx + node.second.first <<endl;
        }
        return ans;
    }
    void traverse(TreeNode *root, int level, int dir) {
        if (!root) return;
        nodes.push_back({root->val, {dir, level}});
        traverse(root->left, level + 1, dir - 1);
        traverse(root->right, level + 1, dir + 1);
    }
};
