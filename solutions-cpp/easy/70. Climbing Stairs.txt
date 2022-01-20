int ar[46];
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0)
            return 0;
        if(n <= 2)
            return n;
        if(ar[n] == 0 && n > 0)
            ar[n] = climbStairs(n-1) + climbStairs(n-2);
        return ar[n];
    }
};
