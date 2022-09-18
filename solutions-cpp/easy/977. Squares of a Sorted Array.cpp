 
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& v) {
        int n = v.size();
        vector<int> result(n);
        int i = 0, j = n - 1;
        for (int p = n - 1; p >= 0; p--) {
            if (abs(v[i]) > abs(v[j])) {
                result[p] = v[i] * v[i];
                i++;
            } else {
                result[p] = v[j] * v[j];
                j--;
            }
        }
        return result;
    }
};
