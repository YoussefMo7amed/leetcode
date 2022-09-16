
class Solution {
   public:
    static bool sorting(string &a, string &b) {
        if (a.size() == b.size()) {
            return a > b;
        }
        return a.size() > b.size();
    }
    string kthLargestNumber(vector<string> &nums, int k) {
        sort(nums.begin(), nums.end(), sorting);
        return nums[k - 1];
    }
};