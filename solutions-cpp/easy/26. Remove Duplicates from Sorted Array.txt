class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int cnt = 0;
        int n = a.size();
        for (int i = 1; i < n; ++i) {
            if(a[i] == a[i-1]){
                cnt++;
            } else {
                a[i - cnt] = a[i];
            }
        }
        for(auto i : a)
            cout << i << ' ';
        return n - cnt;
    }
};
