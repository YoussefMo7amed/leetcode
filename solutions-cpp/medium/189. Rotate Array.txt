class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(k > n)
            k = k%n;
        vector <int> ans;
        for(int i =  n-k ; i<n; i++){
            ans.push_back(nums[i]);
            cout << nums[i] << ' ';

        }
        for(int i = 0 ; i < n - k; i++){
            ans.push_back(nums[i]);
            cout << nums[i] << ' ';

        }
        nums = ans;
    }
};
