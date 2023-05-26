class Solution {
   public:
    vector<vector<char>> board;
    bool existsHorizontally(int x, int y, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == c && i != y) {
                cout << "existsHorizontally";
                return true;
            }
        }
        return false;
    }
    bool existsVertically(int x, int y, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == c && i != x) {
                cout << "existsVertically";
                return true;
            }
        }
        return false;
    }
    bool existsInBox(int x, int y, char c) {
        int verticalShifting = 0, horizontalShifting = 0;

        if (y / 3 == 1)
            verticalShifting = 3;
        else if (y / 3 == 2)
            verticalShifting = 6;

        if (x / 3 == 1)
            horizontalShifting = 3;
        else if (x / 3 == 2)
            horizontalShifting = 6;

        for (int i = 0 + horizontalShifting; i < 3 + horizontalShifting; i++) {
            for (int j = 0 + verticalShifting; j < 3 + verticalShifting; j++) {
                if (board[i][j] == c && i != x && j != y) {
                    cout << "existsInBox";
                    return true;
                }
            }
        }
        return false;
    }
    bool exists(int x, int y, char c) {
        return existsVertically(x, y, c) || existsHorizontally(x, y, c) ||
               existsInBox(x, y, c);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        this->board = board;
        char c;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                c = board[i][j];
                if (c != '.' && exists(i, j, c)) return false;
            }
        }
        return true;
    }
};
