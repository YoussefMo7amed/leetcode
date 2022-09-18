class Solution {
public:
    void reverseString(vector <char> &s) {
        int n = s.size();
        for(int i = 0; i < (n+1)/2; i++){
            swap(s[i], s[n-i-1]);
        }
        for(auto i:s)
            cout << i;
    }
};
===========
// recursion way

class Solution {
   public:
    void reverseString(vector<char> &s) { rev(s, 0, s.size() - 1); }
    void rev(vector<char> &s, int left, int right) {
        if (left >= right) return;
        swap(s[left++], s[right--]);
        rev(s, left, right);
    }
};
