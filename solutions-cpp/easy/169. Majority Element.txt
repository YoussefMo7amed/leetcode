class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;
        map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second > m)
                return i.first;
        }
        return 0;
    }
};
