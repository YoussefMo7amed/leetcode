class Solution {
public:
    int indx_Right(char c){
        char right [] = { ')', '}', ']'};
        for(int i = 0; i < 3 ; i++)
            if(right[i] == c)
                return i;
        return -1;
    }
    char opp(int indx, bool dir){ // 0 left, 1 right
        char right [] = { ')', '}', ']'};
        char left [] =  {'(',  '{','[' };
        return (dir? left[indx]:right[indx]); // return the opposite
    }
    bool isValid(string s) {
        stack <char> st;
        for(auto c: s){
            if(st.empty()){
                st.push(c);
            } else {
                char top = st.top();
                if(indx_Right(c) != -1){
                    if(opp(indx_Right(c), 1) == top)
                        st.pop();
                    else
                        return false;
                } else {
                    st.push(c);
                }
            }
        }
        return st.size() == 0;
    }
};
