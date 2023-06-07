#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr){
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != d)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if (mx - mn == 0) {
            return true;
        }
        
        if ((mx - mn) % (n - 1) != 0) {
            return false;
        }
        
        int d = (mx - mn) / (n - 1);
        set<int> s;
        
        for (int i = 0; i < n; i++) {
            if ((arr[i] - mn) % d != 0) {
                return false;
            }
            s.insert(arr[i]);
        }
        
        return s.size() == n;
    }
};