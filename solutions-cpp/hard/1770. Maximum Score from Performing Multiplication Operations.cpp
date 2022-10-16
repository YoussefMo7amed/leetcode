class Solution {
   public:
    vector<vector<int>> dp;
    int calc(vector<int> &v, vector<int> &mult, int s, int e, int i) {
        if (i >= mult.size()) {
            return 0;
        }
        if (dp[i][s] != INT_MIN) return dp[i][s];
        int left = mult[i] * v[s] + calc(v, mult, s + 1, e, i + 1);
        int right = mult[i] * v[e] + calc(v, mult, s, e - 1, i + 1);
        return dp[i][s] = max(left, right);
    }
    int maximumScore(vector<int> &v, vector<int> &mult) {
        int n = v.size();
        int m = mult.size();
        dp.assign(m + 1, vector<int>(m + 1, INT_MIN));
        return calc(v, mult, 0, v.size() - 1, 0);
    }
};