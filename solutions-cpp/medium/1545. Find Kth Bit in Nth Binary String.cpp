class Solution {
    vector<char> old;

   public:
    string gen(int n) {
        if (n < 2) return "0";
        string s;
        s = gen(n - 1);
        string rev_inv = s;
        reverse(rev_inv.begin(), rev_inv.end());
        for (char &c : rev_inv) c ^= 1;
        return s + "1" + rev_inv;
    }
    char findKthBit(int n, int k) { return gen(n)[k - 1]; }
};
