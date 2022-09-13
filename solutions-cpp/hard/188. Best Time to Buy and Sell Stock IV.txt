
class Solution {
   public:
    int ans(vector<int> &prices, int n, int day, int buy, int transaction,
            vector<vector<vector<int>>> &dp) {
        if (day == n || transaction == 0) return 0;  // base case

        if (dp[day][buy][transaction] != -1)
            return dp[day][buy][transaction];  // already calculated
        int profit;

        // we have 3 states:
        // 1: skip (don't do any thing)
        // 2: buy
        // 3: sell (but depends if you bought before)

        if (buy == 0) {  // We can buy the stock
            profit =
                max(ans(prices, n, day + 1, 0, transaction, dp),
                    -prices[day] + ans(prices, n, day + 1, 1, transaction, dp));
        }
        if (buy == 1) {  // We can sell the stock
            profit = max(
                ans(prices, n, day + 1, 1, transaction, dp),
                prices[day] + ans(prices, n, day + 1, 0, transaction - 1, dp));
        }
        return dp[day][buy][transaction] =
                   profit;  // save the value then return it.
    }
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        // memoization
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return ans(prices, n, 0, 0, k, dp);
    }
};
