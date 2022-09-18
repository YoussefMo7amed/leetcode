class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int mx = INT_MIN;
        int x;
        for(int i = 0; i < nums.size(); i++){
            x = nums[i];
            cur += x;
            if(cur < x)
                cur = x;
            if(cur > mx)
                mx = cur;
        }
        return mx;
    }
};
================
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int mx = INT_MIN;
        for(auto i: nums){
            cur += i;
            if(cur < i)
                cur = i;
            if(cur > mx)
                mx = cur;
        }
        return mx;
    }
};
