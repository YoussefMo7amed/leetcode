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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum - root->val == 0;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

// faster solution

class Solution {
   public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        stack<pair<TreeNode *, int>> st;
        st.push({root, root->val});
        TreeNode *node = root;
        int sum = root->val;
        while (st.size()) {
            node = st.top().first;
            sum = st.top().second;
            st.pop();
            if (node->left == NULL && node->right == NULL) {
                if (sum == targetSum) return true;
            } else {
                if (node->left) st.push({node->left, sum + node->left->val});
                if (node->right) st.push({node->right, sum + node->right->val});
            }
        }
        return false;
    }
};
