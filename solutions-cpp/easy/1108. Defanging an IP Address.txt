class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(char c: address){
            if(c == '.'){
                ans.push_back('[');
                ans.push_back(c);
                ans.push_back(']');

            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
