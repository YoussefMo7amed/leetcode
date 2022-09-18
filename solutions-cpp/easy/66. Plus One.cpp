class Solution {
public:
    vector<int> plusOne(vector<int>& ar) {
        int n = ar.size() - 1;
        int tmp;
        bool add = false;
        int last;
        if(ar[n] + 1 < 10) {
            ar[n]++;
        }
        else {
            int prev = 1;
            for(int i = n; i >= 0; i--){
                if(ar[i]+prev < 10){
                    ar[i] +=prev;
                    prev = 0;
                } else {
                    ar[i] = 0;
                    prev = 1;
                    if(i == 0)
                        add = true;
                }
            }
            if(add) {
                ar.insert(ar.begin(), 1);
            }
        }
        return ar;
    }
};
