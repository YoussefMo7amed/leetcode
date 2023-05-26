class Solution {
public:
    string rearranged(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        string current;
        for (string s : strs) {
            current = rearranged(s);
            mp[current].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto row : mp) {
            ans.push_back(row.second);
        }
        return ans;
    }
};
