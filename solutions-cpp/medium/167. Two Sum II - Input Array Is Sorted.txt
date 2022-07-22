class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector <int > ans;
        int n = v.size();
        int p1 = 0, p2 = n - 1;
        while(p1 < p2){
            if(v[p1] + v[p2] == target){
                ans.push_back(p1+1);
                ans.push_back(p2+1);
                break;
            }
            if(v[p1] + v[p2] > target){
                p2--;
            } else {
                p1++;
            }
        }
        return ans;
    }
};
