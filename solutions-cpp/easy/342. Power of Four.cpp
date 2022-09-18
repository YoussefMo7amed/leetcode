class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double x = log(n)/log(4);
        cout << log(n)/log(4);
        long long y = log(n)/log(4);

        return abs(x-y) < 0.0000001;
    }
};
