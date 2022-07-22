class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        long long sum = 0;
        int indx = -1;
        for (int i : nums) sum += i;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum - nums[i] - cur == cur) {
                indx = i;
                break;
            }
            cur += nums[i];
        }
        return indx;
    }
};
