class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> v;

        vector <int> cur= intervals[0];

        for(int i = 1; i < intervals.size(); i++){
            if(cur[1] >= intervals[i][0] && cur[1] <= intervals[i][1] ||cur[0] <= intervals[i][1] && cur[1] >= intervals[i][0]){
                cur[0] = min(cur[0], intervals[i][0]);
                cur[1] = max(cur[1], intervals[i][1]);
            } else {
                v.push_back(cur);
                cur = intervals[i];
            }
        }
        v.push_back(cur);
        return v;
    }
};
