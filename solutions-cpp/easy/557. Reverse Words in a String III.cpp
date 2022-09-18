class Solution {
public:
    string reverseWord(string s){
        reverse(s.begin(), s.end());
        return s;
    }

    string reverseWords(string s) {
        string ans;
        int p = 0;
        int n = s.size();
        int i;
        for(i = 0; i <n; i++){
            if(i + 1 < n && s[i+1] == ' ' && s[i] != ' '){
                // cout << reverseWord(s.substr(p, i-p + 1));
                ans.append(reverseWord(s.substr(p, i-p + 1)));
                p = i+1;
            } else {
                if(s[i] == ' '){
                    // cout << s[i];
                    ans.push_back(s[i]);
                    p++;
                }
            }
        }
        // cout << reverseWord(s.substr(p, i-p + 1));
        ans.append(reverseWord(s.substr(p, i-p + 1)));

        return ans;
    }
};
