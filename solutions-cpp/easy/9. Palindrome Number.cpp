class Solution {
public:
    bool isPalindrome(int x) {
        stack <char> s;
        queue<char> q;
        char c;
        if(x < 0)
            return false;
        x = abs(x);
        while(x){
            c = (x%10)-'0';
            q.push(c);
            s.push(c);
            x/=10;
        }
        while(q.size()){
            if(s.top() != q.front())
                return false;
            q.pop();
            s.pop();
        }
        return true;
    }
};

// second solution
// compare digit by digit from left and right
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if( x == 0)
            return true;
        long long d = ceil(log10(x));
        printf("%d\n", d);
        long long left, right;
        left = right = x;

        for (int i = 0; i < d; i++) {
            long long start = left / pow(10, d - i - 1);

            left %= (long long )pow(10, d - i - 1);

            long long end;

            long long md = (long long) round(pow(10, i+1));
            right = x % md;
            long long  dv = (long long)round(pow(10, i));
            end = right/dv;

            if (start != end)
                return false;
        }
        return true;
    }
};
