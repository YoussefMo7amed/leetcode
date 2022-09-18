class Solution {
public:
int mySqrt(int t) {
        int l = 0;
        int r = t ;

        long long m = 0;
        while(l <= r)
        {
            m = (l + r)/2;
            if(m * m == t)
                return m;
            else if (m * m > t)
                r = m - 1;
            else
                l = m + 1 ;
        }
        if(m*m > t)
            m--;
        return m;
    }
};
