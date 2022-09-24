class Solution {
   public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bits = 0;
        for (int i = 1; i <= n; i++) {
            // search about "Detect if a number is power of 2 using bitwise operators"
            if (!(i & (i - 1))) bits++;
            // search about bit shifting
            ans = ((ans << bits) + i) % MOD;
        }
        return ans;
    }
};
