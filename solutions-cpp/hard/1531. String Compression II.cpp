
int memo[100][26][100][100];
class Solution {
   public:
    string str;
    int backtrack(int index, int prev, int length, int k) {
        if (k < 0) return INT_MAX;
        if (index >= str.size()) return 0;

        if (memo[index][prev][length][k] != -1)
            return memo[index][prev][length][k];

        int leave = backtrack(index + 1, prev, length, k - 1);

        int keep = 0;
        if (str[index] - 'a' == prev) {
            if (length == 1 || length == 9 || length == 99) {
                keep += 1;
            }
            keep = keep + backtrack(index + 1, prev, length + 1, k);
        } else {
            keep = 1 + backtrack(index + 1, str[index] - 'a', 1, k);
        }
        return memo[index][prev][length][k] = min(leave, keep);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        memset(memo, -1, sizeof(memo));
        return backtrack(0, 25, 0, k);
    }
};