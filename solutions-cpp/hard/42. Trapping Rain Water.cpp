class Solution {
   public:
    int trap(vector<int> &h) {
        int n = h.size();
        vector<int> max_left(n, 0), max_right(n, 0);

        max_left[0] = h[0];
        max_right[n - 1] = h[n - 1];

        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], h[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], h[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (min(max_left[i], max_right[i]) - h[i]);
        }
        return ans;
    }
};