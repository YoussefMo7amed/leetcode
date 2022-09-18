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
