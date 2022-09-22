class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even = 0;
        for(int x: nums)
            if(x%2==0)
                even += x;
        int n = nums.size();
        vector<int> ans;
        for(int i =0; i<n;i++){
            int val = queries[i][0];
            int index = queries[i][1];
            
            if(nums[index]%2 == 0)
                even -= nums[index];
            
            nums[index] += val;
            
            if(nums[index]%2 == 0)
                even += nums[index];
            ans.push_back(even);
        }
        return ans;
    }
};