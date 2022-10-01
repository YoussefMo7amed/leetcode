class Solution {
   public:
    vector<int> memo;
    bool is_valid(string s) {
        if (s.size() == 1) {
            return s[0] != '0';
        }
        return !((s[0] == '0' || s[0] > '2') || (s[0] == '2' && s[1] > '6'));
    }
    int count(string &s, int i) {
        if (i == s.size()) {
            return 1;
        }
        if (memo[i] != -1) return memo[i];

        int one = 0;
        int two = 0;
        if (i + 1 <= s.size() && is_valid(s.substr(i, 1))) {
            one = count(s, i + 1);
        }
        if (i + 2 <= s.size() && is_valid(s.substr(i, 2))) {
            two = count(s, i + 2);
        }
        return memo[i] = one + two;
    }
    int numDecodings(string s) {
        memo.resize(101, -1);
        return count(s, 0);
    }
};