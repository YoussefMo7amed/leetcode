class Solution {
   public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> ans;
        int left = 0;
        int right = arr.size() - 1;

        // excluding elements which are not closer
        while (right - left >= k) {
            if (abs(arr[left] - x) > abs(arr[right] - x))
                left++;
            else
                right--;
        }
        return vector<int>(arr.begin() + left, arr.begin() + right+1);
    }
};