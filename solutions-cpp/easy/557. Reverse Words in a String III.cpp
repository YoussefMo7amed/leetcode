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
        ans.append(reverseWord(s.substr(p, i-p + 1)));

        return ans;
    }
};
// or
class Solution {
   public:
    string reverseWords(string s) {
        string ans = "";
        stringstream stream(s);
        string word;
        while (getline(stream, word, ' ')) {
            reverse(word.begin(), word.end());
            ans += word + " ";
        }
        ans.pop_back();
        return ans;
    }
};
