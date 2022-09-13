
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Using one pass algoritm
        int mn = INT_MAX;
        int mx = 0;
        for(int i: prices){
            mn = min(mn , i);
            mx = max(mx, i - mn);
        }
        return mx;
    }
};

/// other Solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        int l = 0, r = 1, mx = 0;
       while(r < n){
            if(prices[l] < prices[r]){
                mx = max(mx, prices[r] - prices[l]);
            } else{
                l = r;
            }
           r++;
        }
        return mx;
    }
};
