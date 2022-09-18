class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
    map<int,int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        mp[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int df = target - nums[i];
        map<int,int>::iterator it = mp.find(df);
        if(it != mp.end() && i != mp[df]){
            sol.push_back(i);
            sol.push_back(mp[df]);
            break;
        }
    }
    return sol;
    }
};
