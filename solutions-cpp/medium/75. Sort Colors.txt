class Solution {
   public:
    void sortColors(vector<int>& ar) {
        // 0 1 2
        int n = ar.size();
        int i = 0;
        int j = i + 1;
        // first make them adjasnt
        while (i < n) {
            while (j < n && ar[i] != ar[j]) {
                j++;
            }
            if (j < n && ar[i] == ar[j]) {
                swap(ar[i + 1], ar[j]);
                i++;
                j = i + 1;
            }
            if (j == n) {
                i++;
                j = i + 1;
            }
        }
        // then arrange them
        int min_idx;
        for (i = 0; i < n - 1; i++) {
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (ar[j] < ar[min_idx]) min_idx = j;

            // Swap the found minimum element with the first element
            swap(ar[min_idx], ar[i]);
        }
    }
};
