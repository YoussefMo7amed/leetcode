 
class Solution {
   public:
    string addBinary(string a, string b) {
        bool rem = false;
        stack<char> s;

        while (a.size() && b.size()) {
            if (a.back() == b.back() && a.back() == '1') {
                if (!rem) {
                    rem = true;
                    s.push('0');
                } else {
                    s.push('1');
                }
            } else if (a.back() == b.back() && a.back() == '0') {
                if (rem) {
                    s.push('1');
                    rem = false;
                } else {
                    s.push('0');
                }
            } else {
                if (rem) {
                    s.push('0');
                } else {
                    s.push('1');
                }
            }
            a.pop_back();
            b.pop_back();
        }
        while (a.size()) {
            if (a.back() == '0') {
                if (rem) {
                    s.push('1');
                    rem = false;
                } else {
                    s.push('0');
                }
            } else {
                if (rem) {
                    s.push('0');
                } else {
                    s.push('1');
                }
            }
            a.pop_back();
        }
        while (b.size()) {
            if (b.back() == '0') {
                if (rem) {
                    s.push('1');
                    rem = false;
                } else {
                    s.push('0');
                }
            } else {
                if (rem) {
                    s.push('0');
                } else {
                    s.push('1');
                }
            }
            b.pop_back();
        }
        if (rem) {
            s.push('1');
        }
        string ans = "";
        while (s.size()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
