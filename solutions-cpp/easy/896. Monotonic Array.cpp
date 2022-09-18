class Solution {
   public:
    bool isMonotonic(vector<int> &nums) {
        int n = nums.size();
        if(n <= 2)
            return 1;
        int sign = 0;
        for (int i = 1; i < n; i++) {
            if(sign == 0){
                sign = nums[i] - nums[i - 1];
                continue;
            }
            if (nums[i] - nums[i - 1] > 0 && sign < 0) {
                return false;
            }
            if (nums[i] - nums[i - 1] < 0 && sign > 0) {
                return false;
            }
        }
        return true;
    }
};
