
class Solution {
   public:
    vector<bool> vis;
    void outcome(vector<int> &in, vector<vector<int>> &ans, vector<int> current,
                 int indx, int n) {
        if (current.size() == n) {
            ans.push_back(current);
            return;
        }
        vis[indx] = true;

        for (int i = 0; i < n; i++) {
            if (!vis[i] && i != indx) {
                current.push_back(in[i]);
                outcome(in, ans, current, i, n);
                current.pop_back();
            }
        }
        vis[indx] = false;
    }
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vis = vector<bool>(n, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            outcome(nums, ans, {nums[i]}, i, n);
        }
        return ans;
    }
};