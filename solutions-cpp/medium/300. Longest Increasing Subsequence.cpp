// it's straight forward question, you need to know the longest increasing subsequence technique
class Solution {
   public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    ans[i] = max(ans[i], ans[j] + 1);
                }
            }
        }
        int mx = -1;
        for (int i : ans) mx = max(i, mx);
        return mx;
    }
};
