class Solution {
   public:
    bool reorderedPowerOf2(int n) {
        vector<string> powersOf2;
        string number;
        for (int i = 1; i <= 1e9; i *= 2) {
            number = to_string(i);
            sort(number.begin(), number.end());
            powersOf2.push_back(number);
        }
        string val = to_string(n);
        sort(val.begin(), val.end());
        for(string number: powersOf2){
            if(val.size() == number.size()){
                if(val == number)
                    return true;
            }
        }
        return false;
    }
};
