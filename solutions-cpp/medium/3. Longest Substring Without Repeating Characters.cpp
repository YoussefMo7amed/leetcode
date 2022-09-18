class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start){
                cout << s[i] << endl;
                start = dict[ s[i] ];
                cout << start << endl;
            }
            dict[s[i]] = i;

            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
