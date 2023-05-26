// Runtime 31 ms  - Beats 40.38%
// Memory 24 MB - Beats 84.82%

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        long long mult = 1;
        for (int i : nums) {
            if (i == 0) {
                if (zero >= 1) {
                    zero++;
                    mult = 0;
                    break;
                }
                zero++;
                continue;
            }
            mult *= i;
        }
        vector<int> ans(nums.size(), 0);
        if (zero > 1) {
            return ans;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (zero > 0 && nums[i] != 0) {
                ans[i] = 0;
            }
            else {
                if (nums[i] == 0) {
                    ans[i] = mult;
                    break;
                }
                ans[i] = mult / nums[i];
            }
        }
        return ans;
    }
};

// Runtime 16 ms  - Beats 98.3%
// Memory 25.1 MB - Beats 19.92%

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<int> left(n+1, 1);
        vector<int> right(n+1, 1);

        for(int i = 1 ; i <= n; i++){
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i = n-2 ; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i = 0 ; i < n; i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
