// we take advantage of BST
class Solution {
   public:
    int INF = 1e9;
    vector<int> numbers;
    void getNumbers(TreeNode* root) {
        if (root == nullptr) return;
        getNumbers(root->left);
        numbers.push_back(root->val);
        getNumbers(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        getNumbers(root);
        int mn = INF;
        for (int i = 1; i < numbers.size(); i++) {
            mn = min(mn, numbers[i] - numbers[i - 1]);
        }
        return mn;
    }
};

// or (more time complexity)
class Solution {
   public:
    int INF = 1e9;
    vector<int> numbers;
    void getNumbers(TreeNode* root) {
        if (root == nullptr) return;
        numbers.push_back(root->val);
        getNumbers(root->left);
        getNumbers(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        getNumbers(root);
        sort(numbers.begin(), numbers.end());
        int mn = INF;
        for (int i = 1; i < numbers.size(); i++) {
            mn = min(mn, numbers[i] - numbers[i - 1]);
        }
        return mn;
    }
};