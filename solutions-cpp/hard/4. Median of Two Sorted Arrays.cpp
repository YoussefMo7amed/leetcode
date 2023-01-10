
class Solution {
   public:
    // O(n) solution
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
        vector<int> all;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                all.push_back(a[i++]);
            } else {
                all.push_back(b[j++]);
            }
        }
        while (i < a.size()) {
            all.push_back(a[i++]);
        }
        while (j < b.size()) {
            all.push_back(b[j++]);
        }
        double ans;
        int md = all.size() / 2;
        if (all.size() % 2 == 0)
            ans = (all[md] * 1.0 + all[md - 1] * 1.0) / 2.0;
        else
            ans = all[md];
        return ans;
    }
};