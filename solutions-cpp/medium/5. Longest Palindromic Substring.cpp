
class Solution {
   public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int oddCase = 0, evenCase = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            oddCase = expanding(s, i, i);
            evenCase = expanding(s, i, i + 1);
            len = max(oddCase, evenCase);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + (len / 2);
            }
        }
        return s.substr(start, end - start + 1);
    }
    int expanding(string &s, int start, int end) {
        if (s.empty() || start > end) {
            return 0;
        }
        while (start >= 0 && end < s.size() && (s[start] == s[end]))
            start--, end++;

        return end - start - 1;
    }
};
