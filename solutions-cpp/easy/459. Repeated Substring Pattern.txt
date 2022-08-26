class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) return false;
        string ss = s.substr(1) + s.substr(0, s.size() - 1);
        return ss.find(s) != string::npos;
    }
};
