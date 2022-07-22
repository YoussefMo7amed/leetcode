 
class Solution {
   public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int cs = 0, ans = 0;
        set<int> s;
        s.insert(0);
        for (int i : nums) {
            cs += i;
            if (s.find(cs - target) != s.end()) {
                ans++;
                s.clear();
                cs = 0;
            }
            s.insert(cs);
        }
        return ans;
    }
};
