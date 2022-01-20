class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode *> s;
        vector <int> v;
        while(!s.empty() || root != NULL){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }
};
