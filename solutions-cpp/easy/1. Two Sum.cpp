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

// or

// naive solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans = { i, j };
                    found = true;
                }
            }
            if (found) break;
        }
        return ans;
    }
};

// or


// naive solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return  { i, j };
                }
            }
        }
        return {};
    }
};
