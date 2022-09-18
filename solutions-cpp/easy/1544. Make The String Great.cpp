class Solution {
   public:
    bool bad(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) == tolower(s[i + 1]) &&
                ((isupper(s[i]) && islower(s[i + 1])) ||
                 (islower(s[i]) && isupper(s[i + 1])))) {
                return true;
            }
        }
        return false;
    }
    string makeGood(string s) {
        string ans = s;

        while (bad(s)) {
            for (int i = 0; i < s.size(); i++) {
                if (tolower(s[i]) == tolower(s[i + 1]) &&
                    ((isupper(s[i]) && islower(s[i + 1])) ||
                     (islower(s[i]) && isupper(s[i + 1])))) {
                    ans =
                        s.substr(0, i) +
                        (i + 1 < s.size() ? s.substr(i + 2, s.size() - (i + 2))
                                          : "");
                }
            }
            s = ans;
        }
        return ans;
    }
};

