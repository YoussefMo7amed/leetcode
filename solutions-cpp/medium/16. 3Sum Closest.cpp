class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX / 10, currentSum = 0;
        for (int first = 0; first < n; first++) {
            int second = 0, third = n - 1;
            while (second < third) {
                if (first == second || first == third) {
                    if (first == second) {
                        second++;
                    }
                    if (first == third) {
                        third--;
                    }
                    continue;
                }
                currentSum = nums[first] + nums[second] + nums[third];
                if (currentSum == target) return currentSum;
                if (abs(currentSum - target) < abs(ans - target))
                    ans = currentSum;
                if (currentSum > target)
                    third--;
                else if (currentSum < target)
                    second++;
                else
                    return currentSum;
            }
        }
        return ans;
    }
};