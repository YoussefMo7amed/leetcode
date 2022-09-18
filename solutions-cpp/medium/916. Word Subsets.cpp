class Solution {
   public:
    vector<int> occurrence(string s) {
        vector<int> v(26, 0);
        for (char c : s) v[c - 'a']++;
        return v;
    }
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<string> ans;
        vector<int> bMax(26, 0);
        for (string b : words2) {
            vector<int> bOccurrence = occurrence(b);
            for (int i = 0; i < 26; i++) {
                bMax[i] = max(bMax[i], bOccurrence[i]);
            }
        }
        for (string a : words1) {
            vector<int> aOccurrence = occurrence(a);
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (aOccurrence[i] < bMax[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(a);
        }
        return ans;
    }
};
