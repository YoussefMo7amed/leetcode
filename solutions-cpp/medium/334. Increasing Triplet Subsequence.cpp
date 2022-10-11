/*
if we know the minimum value from left till (i)
and max value from right till (i)
if minimum left value < nums[i] < maximum right value then return true;
*/
class Solution {
   public:
    bool increasingTriplet(vector<int> &nums) {
        int n = nums.size();
        vector<int> leftMin(n);
        vector<int> rightMax(n);

        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (leftMin[i] < nums[i] && nums[i] < rightMax[i]) return true;
        }
        return false;
    }
};
// =========================
// faster solution:
class Solution {
   public:
    bool increasingTriplet(vector<int> &nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int x : nums) {
            if (x <= first) {
                first = x;
            } else if (x <= second) {
                second = x;
            } else {
                return true;
            }
        }
        return false;
    }
};
