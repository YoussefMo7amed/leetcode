class Solution {
   public:
    int M = 1000000000 + 7;
    int memo(int m, int n, int s, int i, int j,
             vector<vector<vector<int>>> &mem) {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (s == 0) return 0;
        if (mem[i][j][s] >= 0) return mem[i][j][s];
        mem[i][j][s] = ((memo(m, n, s - 1, i + 1, j, mem) +memo(m, n, s - 1, i - 1, j, mem)) %M +
                        (memo(m, n, s - 1, i, j + 1, mem) + memo(m, n, s - 1, i, j - 1, mem)) %M)
                        %M;
        return mem[i][j][s];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> v(m);
        for (int i = 0; i < m; i++) {
            v[i].resize(n);
            for (int j = 0; j < n; j++) {
                v[i][j].resize(maxMove + 1, -1);
            }
        }
        return memo(m, n, maxMove, startRow, startColumn, v);
    }
};
