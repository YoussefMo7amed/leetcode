bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long  l = 0 , r = n;
        while(l < r)
        {
            long long m = l + (r-l) / 2;
            if(isBadVersion(m) && !isBadVersion(m-1))
                return m;
            else if (isBadVersion(m) && isBadVersion(m-1))
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};
===================
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
         int st = 1, en = n;
         while(st < en){
             int mid = st + (en-st)/2;
             if(isBadVersion(mid)){
                 en = mid;
             } else {
                 st = mid + 1;
             }
         }
         return en;
    }
};
