class Solution {
   public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;

        if (n > m) swap(n, m);

        int ar[m][n];
        for (int i = 0; i < n; i++) {
            ar[0][i] = (n - 1) - i;
            ar[1][i] = i + 1;
        }
        for (int i = 2; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    ar[i][j] = 1;
                } else {
                    ar[i][j] = ar[i - 1][j] + ar[i][j - 1];
                }
            }
        }
        return ar[m - 1][n - 1];
    }
};
