class Solution {
   public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        // Note i changed it from m*n to n*m
        int n = mat.size();
        int m = mat[0].size();

        for (int j = 0; j < m; j++) {
            vector<int> diagonal;
            for (int i = 0, k = j; i < n && k < m; i++, k++) {
                diagonal.push_back(mat[i][k]);
            }
            sort(diagonal.begin(), diagonal.end());

            for (int i = 0, k = j, cnt = 0; i < n && k < m; i++, k++, cnt++) {
                mat[i][k] = diagonal[cnt];
            }
            diagonal.clear();
        }
        for (int i = 1; i < n; i++) {
            vector<int> diagonal;
            for (int j = 0, k = i; j < m && k < n; j++, k++) {
                diagonal.push_back(mat[k][j]);
            }
            sort(diagonal.begin(), diagonal.end());
            for (int j = 0, k = i, cnt = 0; j < m && k < n; j++, k++, cnt++) {
                mat[k][j] = diagonal[cnt];
            }
            diagonal.clear();
        }
        return mat;
    }
};
