class Solution {
   public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int left = -1, right = n;
        while (++left < --right) {
            for (int i = 0; i < right - left; i++) {
                int top = left, bottom = right;

                // save the top left cell
                int topLeft = matrix[top][left + i];

                // move cells
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = topLeft;
            }
        }
    }
};
