class Solution {
    vector<vector<int>> memo;

   public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        memo.assign(301, vector<int>(11, -1));
        return dp(jobDifficulty, d, 0);
    }
    int dp(vector<int> &jobs, int d, int currentJob) {
        if (d == 1) {
            return memo[currentJob][d] = *max_element(jobs.begin() + currentJob, jobs.end());
        }
        if (memo[currentJob][d] != -1) return memo[currentJob][d];
        int mx = INT_MIN;
        int res = INT_MAX;
        for (int i = currentJob; i <= jobs.size() - d; i++) {
            mx = max(jobs[i], mx);
            res = min(res, mx + dp(jobs, d - 1, i + 1));
        }
        return memo[currentJob][d] = res;
    }
};
