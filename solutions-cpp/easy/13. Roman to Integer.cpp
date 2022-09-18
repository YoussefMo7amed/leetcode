class Solution {
public:
    int romanToInt(string s) {
        char r[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int v[] = {1, 5, 10, 50, 100, 500, 1000};
        map<char, int> mp;
        for(int i = 0; i < 7; i++){
            mp[r[i]]=v[i];
        }

        int ans=0;
        for(int i =0; i<s.size(); i++){
            if(i+1 <s.size() && mp[s[i]] < mp[s[i+1]]){
                ans+= (mp[s[i+1]] - mp[s[i]]);
                i++;
            } else {
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};


