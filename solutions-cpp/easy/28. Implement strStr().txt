// using built-in function
class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = haystack.find(needle);
        if(k > haystack.size())
            return -1;
        else
            return k;
    }
};
==================
// implement strStr()
class Solution {
   public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        if (h < n) return -1;
        int indx = -1;
        int i = 0, j = 0;
        for (; i < h; i++) {
            if (haystack[i] == needle[j] && j != n) {
                j++;
                if (indx == -1) indx = i;
            } else {
                j = 0;
                if (indx != -1) i = indx;
                indx = -1;
            }
            if (j == n) return indx;
        }
        return -1;
    }
};
