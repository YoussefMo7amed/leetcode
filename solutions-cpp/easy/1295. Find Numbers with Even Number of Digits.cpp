class Solution {
   public:
    int findNumbers(vector<int>& v) {
        int even = 0;
        for (int i : v) {
            int d = floor(log10(i)) + 1;
            cout << d << endl;
            if (d % 2 == 0) even++;
        }
        return even;
    }
};
