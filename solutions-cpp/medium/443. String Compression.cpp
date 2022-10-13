class Solution {
   public:
    int compress(vector<char> &chars) {
        string s;
        char prev = chars[0];
        int cnt = 1;
        for (int i = 1; i <= chars.size(); i++) {
            if (i < chars.size() && chars[i] == prev) {
                cnt++;
            } else {
                s.push_back(prev);
                if (cnt > 1) {
                    s += to_string(cnt);
                }
                cnt = 1;
                if (i < chars.size()) prev = chars[i];
            }
        }
        chars.clear();
        for (char c : s) {
            chars.push_back(c);
        }
        return chars.size();
    }
};