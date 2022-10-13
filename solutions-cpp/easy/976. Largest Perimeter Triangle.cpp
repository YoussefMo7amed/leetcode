class Solution {
   public:
    int largestPerimeter(vector<int> &nums) {
        sort(nums.rbegin(), nums.rend());
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (isValid(vector<int>(nums.begin() + i, nums.begin() + i + 3))) {
                ans = sum(vector<int>(nums.begin() + i, nums.begin() + i + 3));
                break;
            }
        }
        return ans;
    }
    bool isValid(vector<int> v) {
        int sum = 0;
        for (int x : v) sum += x;
        for (int x : v) {
            if (x >= sum - x) return false;
        }
        return true;
    }
    int sum(vector<int> v) {
        int sum = 0;
        for (int x : v) sum += x;
        return sum;
    }
};