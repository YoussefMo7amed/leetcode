class Solution {
   public:
    vector<int> dp;

    Solution() {
        dp.resize(1001); // max value of target
        fill(dp.begin(), dp.end(), -1);
    }

    int combinationSum4(vector<int> &nums, int target, int current = 0) {
        if (current > target) return 0;
        if (current == target) return 1;
        if (dp[current] != -1) return dp[current];
        dp[current] = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (current + nums[i] <= target) {
                dp[current] += combinationSum4(nums, target, current + nums[i]);
            }
        }
        return dp[current];
    }
};
// =====
/*
    I used the top-bottom approach for solving this problem

    example:
    array = [1,2].. targt = 3

    we begin with current sum which is zero

      0
     / \
   1     2
  / \   / \
 2   3 3   4
/ \  - -   x
3 4
- x


 - = return 1
 x = return 0

 as you see there are some branches we can cashe it (use memoization);
*/
