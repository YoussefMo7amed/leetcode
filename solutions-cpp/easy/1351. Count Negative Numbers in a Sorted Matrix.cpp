class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = n * m;
        int tempCol = n;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < tempCol; j++){
                if(grid[i][j] < 0){
                    tempCol = j;
                    if(j == 0) i = m;
                } else {
                    ans--;
                }
            }
        }
        return ans;
    }
};