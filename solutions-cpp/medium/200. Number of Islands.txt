class Solution {
   public:
    const int di[4] = {1, -1, 0, 0};
    const int dj[4] = {0, 0, 1, -1};
    bool vis[300][300];
    int numIslands(vector<vector<char>> &grid) {
        memset(vis, false, sizeof vis);
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    if (vis[i][j]) continue;
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>> &grid, int i, int j) {
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (vis[ni][nj] || grid[ni][nj] == '0') continue;
            if(grid[ni][nj] == '1')dfs(grid, ni, nj);
        }
    }
};
