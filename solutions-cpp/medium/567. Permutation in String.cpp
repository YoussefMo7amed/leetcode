
class Solution {
   public:
    bool checkInclusion(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;

        int ls = s.size(), lt = t.size();
        if (ls > lt) return false;

        for (char c = 'a'; c <= 'z'; c++) {
            ms[c] = 0;
            mt[c] = 0;
        }

        int left = 0, right;

        for (right = 0; right < ls; right++) {
            ms[s[right]]++;
            mt[t[right]]++;
        }
        right--;
        while (right < lt) {
            if (ms == mt) return true;

            right++;

            if (right != lt) {
                mt[t[right]]++;
            }
            mt[t[left]]--;
            left++;
        }
        return false;
    }
};

