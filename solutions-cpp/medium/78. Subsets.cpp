class Solution {
   public:
    map<int, bool> vis;
    void traverse(vector<int> &nums, vector<int> &cur, set<vector<int>> &ans,
                  int indx) {
        int n = nums.size();
        if (indx >= n) return;
        ans.insert(cur);
        for (int i = indx; i < n; i++) {
            if (!vis[i]) {
                cur.push_back(nums[i]);
                vis[i] = true;
                traverse(nums, cur, ans, i);
                cur.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vis[i] = false;
        }
        vector<int> cur;
        traverse(nums, cur, ans, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

// or

class Solution {
   public:
    map<int, bool> vis;
    void traverse(vector<int> &nums, vector<int> &cur, vector<vector<int>> &ans,
                  int indx) {
        int n = nums.size();
        if (indx >= n) return;
        ans.push_back(cur);
        for (int i = indx; i < n; i++) {
            if (!vis[i]) {
                cur.push_back(nums[i]);
                vis[i] = true;
                traverse(nums, cur, ans, i);
                cur.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vis[i] = false;
        }
        vector<int> cur;
        traverse(nums, cur, ans, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
