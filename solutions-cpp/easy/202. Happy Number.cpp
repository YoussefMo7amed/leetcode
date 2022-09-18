class Solution {
   public:
    int sum(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        bool flag = false;
        while (1) {
            if (n == 1) {
                flag = true;
                break;
            }
            if (s.find(n) != s.end()) {
                break;
            }
            s.insert(n);
            n = sum(n);
        }
        return flag;
    }
};
