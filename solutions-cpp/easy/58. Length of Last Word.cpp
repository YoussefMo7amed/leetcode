class Solution {
   public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int last = 0;
        s.push_back(' ');
        for (char c : s) {
            if (c != ' ') {
                ans++;
            } else {
                if (ans > 0) {
                    last = ans;
                }
                ans = 0;
            }
        }
        return last;
    }
};
