class Solution {
   public:
    vector<vector<bool>> vis;
    bool search(vector<vector<char>> &board, string word, string current, int i,
                int j, int m, int n, int c) {
        if (word.length() == c) {
            return word == current;
        }
        // up down left right
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        bool flag = false;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (board[ni][nj] == word[c] && !vis[ni][nj]) {
                vis[ni][nj] = true;
                flag = (search(board, word, current + (word[c]), ni, nj, m, n,
                               c + 1) ||
                        flag);
                vis[ni][nj] = false;
            }
            if (flag) break;
        }
        return flag;
    }
    bool exist(vector<vector<char>> &board, string word) {
        const int m = board.size();
        const int n = board[0].size();

        vis = vector<vector<bool>>(m, vector<bool>(n, 0));

        bool flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    vis[i][j] = true;
                    flag =
                        search(board, word, word.substr(0, 1), i, j, m, n, 1);
                    vis[i][j] = false;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        return flag;
    }
};