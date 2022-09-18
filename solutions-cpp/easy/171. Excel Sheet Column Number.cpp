class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0, postition;
        for(int i =0; i<columnTitle.size(); i++){
            postition  = columnTitle[i] - 'A' + 1;
            ans = ans * 26 + postition;
        }
        return ans;
    }
};
