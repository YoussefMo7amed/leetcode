
class Solution {
   public:
    int minCost(string colors, vector<int> &neededTime) {
        int ans = 0, letter_sum = 0, max_value = 0;
        bool new_letter = true;
        for (int i = 0; i < colors.size(); i++) {
            if (i == 0 || colors[i] != colors[i - 1]) {
                new_letter = true;
                if (i != 0) {
                    ans += letter_sum - max_value;
                }
            } else {
                new_letter = false;
            }
            if (new_letter || i == 0) {
                max_value = neededTime[i];
                letter_sum = neededTime[i];
            } else {
                max_value = max(max_value, neededTime[i]);
                letter_sum += neededTime[i];
            }
        }
        ans += letter_sum - max_value;
        return ans;
    }
};