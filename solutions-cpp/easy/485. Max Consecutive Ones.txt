class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            while (i < v.size() && v[i] == 1) {
                cnt++;
                i++;
            }
            ans = max(ans, cnt);
            cnt = 0;
        }
        return ans;
    }
};
