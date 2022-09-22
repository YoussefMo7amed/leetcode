class Solution {
   public:
    int findLength(vector<int> &v, vector<int> &vv) {
        int n = v.size(), m = vv.size();
        // initialize the 2d dynamic array (vector)
		// size = n + 1
		// initial value: vector of int with size (m + 1) and 0 value;
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		int mx = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (v[i - 1] == vv[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        return mx;
    }
};
