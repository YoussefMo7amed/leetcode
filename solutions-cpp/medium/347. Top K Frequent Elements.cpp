class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        vector<pair<int, int>> v;
        for (auto m : mp) {
            v.push_back(m);
        }
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
            });
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(v[i].first);
        return ans;
    }
};
