 
class Solution {
   public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &ar) {
        sort(ar.begin(), ar.end());
        int ans = 0;

        vector<long long> dp(ar.size(), 1);

        map<int, int> mp;
        for (int i = 0; i < ar.size(); i++) {
            mp[ar[i]] = i;
        }

        for (int i = 0; i < ar.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (ar[i] % ar[j] == 0) {
                    int right = ar[i] / ar[j];
                    if (mp.find(right) != mp.end()) {
                        dp[i] = (dp[i] + dp[j] * dp[mp[right]]) % mod;
                    }
                }
            }
            ans = (ans%mod + dp[i]%mod)%mod;
        }
        return ans;
    }
};
