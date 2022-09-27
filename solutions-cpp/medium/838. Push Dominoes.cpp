/*
The idea is to know which is closer for each cell, say a cell is 2 seconds away from R and 3 seconds away from L; then it will be R, if both have the same distance then it will remain, and if there is a block (R betwen L and the cell or viceversa) then the distance is maximum int.

Example
input:
".L.R...L"

- R:
	{2147483647, 2147483647, 2147483647, 0, 1, 2, 3, 2147483647}

- L:
{1, 0, 2147483647, 2147483647, 3, 2, 1, 0}

- min distance:
{L, L, ., R, R, ., L, L}

answer:
"LL.RR.LL"
*/

class Solution {
   public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n);
        vector<int> right(n);
        int seconds = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                seconds = 0;
            } else if (dominoes[i] == 'L') {
                seconds = INT_MAX;
            } else if (seconds != INT_MAX) {
                seconds++;
            }
            right[i] = seconds;
        }
        seconds = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                seconds = 0;
            } else if (dominoes[i] == 'R') {
                seconds = INT_MAX;
            } else if (seconds != INT_MAX) {
                seconds++;
            }
            left[i] = seconds;
        }
        for (int i = 0; i < n; i++) {
            if (right[i] == left[i]) {
                continue;
            } else {
                if (right[i] < left[i]) {
                    dominoes[i] = 'R';
                } else {
                    dominoes[i] = 'L';
                }
            }
        }
        return dominoes;
    }
};
