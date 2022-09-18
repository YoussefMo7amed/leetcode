
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> ms, mp;

        for (char c = 'a'; c <= 'z'; c++) {
            ms[c] = 0;
            mp[c] = 0;
        }

        vector<int> ans;

        int ls = s.size(), lp = p.size();
        if (ls < lp) return ans;

        int left = 0, right = 0;
        while (right < lp) {
            ms[s[right]]++;
            mp[p[right]]++;
            right++;
        }
        right--;
        while (right < ls) {
            if (ms == mp) {
                ans.push_back(left);
            }
            right++;
            if (right != ls) {
                ms[s[right]]++;
            }
            ms[s[left]]--;
            left++;
        }
        return ans;
    }
};
