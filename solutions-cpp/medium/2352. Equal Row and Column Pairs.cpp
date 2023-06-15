
// Brute force
class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;

        bool exits = true;
        for (int i = 0; i < n; i++) {
            for (int l = 0; l < n; l++) {
                for (int j = 0; j < n; j++) {
                    exits = true;
                    if (grid[i][j] != grid[j][l]) {
                        exits = false;
                        break;
                    }
                }
                if (exits) count++;
            }
        }
        return count;
    }
};