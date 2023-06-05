#include <bits/stdc++.h>
using namespace std;

struct triple {
    int row;
    int column;
    int length = 1;
    triple(int r, int c, int l)
    {
        row = r;
        column = c;
        length = l;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        queue<triple> q;
        set<pair<int, int>> visit;
        vector<vector<int>> direct = { { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 1 }, { -1, -1 }, { 1, -1 }, { -1, 1 } };
        q.push(triple(0, 0, 1));
        while (q.size()) {
            int row = q.front().row;
            int column = q.front().column;
            int length = q.front().length;
            q.pop();

            if (min(row, column) < 0 || max(row, column) >= n or grid[row][column])
                continue;
            if (row == n - 1 and column == n - 1) {
                return length;
            }
            for (auto pr : direct) {
                int i = pr[0];
                int j = pr[1];
                if (visit.find({ row + i, column + j }) == visit.end()) {
                    q.push(triple(row + i, column + j, length + 1));
                    visit.insert({ row + i, column + j });
                }
            }
        }
        return -1;
    }
};