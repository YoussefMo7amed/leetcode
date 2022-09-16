
class Solution {
   public:
    vector<int> findOriginalArray(vector<int> &changed) {
        map<int, int> mp;
        for (int i : changed) mp[i] += 1;
        vector<int> ans;
        // element, occurance
        for (auto &[e, o] : mp) {
            if (e == 0) {
                if (o & 1) {
                    return {};
                } else {
                    vector<int> temp(o / 2, e);
                    ans.insert(ans.end(), temp.begin(), temp.end());
                    mp[e] = 0;
                }
            }
            if (o > 0) {
                // double
                int d = e * 2;
                if (mp.find(d) != mp.end()) {
                    mp[d] -= o;
                    if (mp[d] < 0) return {};
                    vector<int> temp(o, e);
                    ans.insert(ans.end(), temp.begin(), temp.end());
                    mp[e] = 0;
                } else {
                    return {};
                }
            }
        }
        return ans;
    }
};
