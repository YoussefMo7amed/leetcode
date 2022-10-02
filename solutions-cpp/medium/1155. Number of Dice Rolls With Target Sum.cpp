class Solution {
   public:
    vector<vector<int>> memo;
    const int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        memo = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return dp(n, k, target);
    }
    int dp(int left, int k, int current) {
        if(current < 0) return 0;
        if (left == 0) {
            return (current == 0);
        }
        if (memo[left][current] != -1) return memo[left][current];
        int ways = 0;
        for (int i = 1; i <= k; i++) {
            ways = (ways + dp(left - 1, k, current - i)) % MOD;
        }
        return memo[left][current] = ways;
    }
};