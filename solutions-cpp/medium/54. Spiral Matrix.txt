class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> v;
        int sCol = 0;
        int sRow = 0;
        int eCol = mat[0].size() - 1;
        int eRow = mat.size() - 1;
        while (sRow <= eRow && sCol <= eCol) {
            // right
            for (int j = sCol; j <= eCol; j++) {
                v.push_back(mat[sRow][j]);
            }
            sRow++;

            // down
            for (int i = sRow; i <= eRow; i++) {
                v.push_back(mat[i][eCol]);
            }
            eCol--;

            // left
            if (sRow <= eRow) {
                for (int j = eCol; j >= sCol; j--) {
                    v.push_back(mat[eRow][j]);
                }
            }
            eRow--;

            // up
            if (sCol <= eCol) {
                for (int i = eRow; i >= sRow; i--) {
                    v.push_back(mat[i][sCol]);
                }
            }
            sCol++;
        }
        return v;
    }
};
