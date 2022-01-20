class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1)
            return true;
        int m = n;
        while(n>3){
            m /= 3;
            n = ceil(n*1.0/3*1.0);
            // cout << m << '\t' << n << endl;
            if(abs(n-m) != 0)
                return 0;
        }
        return (n == 3);
    }
};
