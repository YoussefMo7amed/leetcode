
class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "11";
        string ans;
        for (int i = 2; i < n; i++) {
            ans += countSay(s);
        }
        return s;
    }
    string countSay(string &s) {
        int size = s.size();
        string newS;
        // char and occurrence
        map<char, int> mp;
        char prev = s[0];
        mp[prev] = 1;
        for (int i = 1; i <= size; i++) {
            if (s[i] != prev || i == size) {
                newS.append(to_string(mp[prev]));
                newS.push_back(prev);
                mp[prev] = 0;
                mp[s[i]] = 1;
                prev = s[i];
            } else {
                mp[prev]++;
            }
        }
        s = newS;
        return newS;
    }
};
