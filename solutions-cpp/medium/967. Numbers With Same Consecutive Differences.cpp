class Solution {
   public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i <= 9; i++) {
            play(i, 1, n, k);
        }
        return ans;
    }
    void play(int cur, int digits, int n, int k) {
        if (digits == n) {
            ans.push_back(cur);
            return;
        }
        if (cur%10 + k <= 9) {
            play(cur * 10 + (cur % 10 + k), digits + 1, n, k);
        }
        if (cur%10 - k >= 0 && k!=0) { // k!=0 because if it = 0 it will be added twice
            play(cur * 10 + (cur % 10 - k), digits + 1, n, k);
        }
    }
};
