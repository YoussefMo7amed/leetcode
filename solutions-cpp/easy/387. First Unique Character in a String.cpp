class Solution {
   public:
    int firstUniqChar(string s) {
        vector<vector<int>> mp(26);

        vector<int> unique;
        int c_indx;
        for (int i = 0; i < s.size(); i++) {
            c_indx = s[i]-'a';
            mp[ c_indx ].push_back(i);
            if( mp[c_indx].size() == 1){
                unique.push_back(c_indx);
            }
        }
        for (int c: unique) {
            if(mp[c].size() == 1){
                return mp[c][0];
            }
        }
        return -1;
    }
};
