
class Solution {
public:
    bool check(string s){
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n - (i + 1)])
                return false;
        }
        return true;
    }
    string fix(string s){
        string ss;
        for(auto c:s){
            if(isalnum(c))
                ss.push_back(tolower(c));
        }
        return ss;
    }
    bool isPalindrome(string s) {
        return check(fix(s));
    }
};
