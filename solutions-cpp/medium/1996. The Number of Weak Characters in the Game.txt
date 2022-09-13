class Solution {
   public:
    static bool srt(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(), srt);
        int n = properties.size();
        int ans = 0;
        int max_current_defense = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (max_current_defense > properties[i][1])
                ans++;
            else
                max_current_defense = properties[i][1];
        }
        return ans;
    }
};