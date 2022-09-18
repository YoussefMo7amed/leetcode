class Solution {
   public:
    int minSetSize(vector<int> &ar) {
        map<int, int> mp;
        for (int i : ar) mp[i] = mp[i] + 1;
        vector<int> freq;
        for (auto i : mp) {
            freq.push_back(i.second);
        }
        sort(freq.begin(), freq.end());
        int ans = 0, removed = 0, half = ar.size() / 2, i = freq.size() - 1;
        while (removed < half) {
            ans += 1;
            removed += freq[i--];
        }
        return ans;
    }
};
