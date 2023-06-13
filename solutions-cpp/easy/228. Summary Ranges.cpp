
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<pair<int, int>> ranges;
        int size= nums.size();
        for (int i = 0; i < size ; i++){
            long long beg = nums[i], last = nums[i];
            for(int j = i+1; j < size ; j++){
                if(nums[j] - last == 1){
                    last = nums[j];
                } else {
                    i = j - 1;
                    break;
                }
            }
            if(ranges.empty() || last != ranges.back().second)
                ranges.push_back({beg, last});
        }
        vector<string> ans;
        for(auto pr : ranges){
            string s ;
            if(pr.first == pr.second){
                s = to_string(pr.first);
            } else {
                s = to_string(pr.first) + "->" + to_string(pr.second);
            }
            ans.push_back(s);
        }
        return ans;
    }
};