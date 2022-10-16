class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> ans;
        vector<pair<int,int>> heights;
        for (auto &v : buildings) {
            heights.push_back(make_pair(v[0], -v[2]));
            heights.push_back(make_pair(v[1], v[2]));
        }
        sort(heights.begin(), heights.end());
        priority_queue<int> heap;
        unordered_map<int, int> mp;
        heap.push(0);
        int pre = -1, cur = 0;
        for (auto &h : heights) {
            if (h.second < 0) {
                heap.push(-h.second);
            } else {
                mp[h.second]++;
                while (!heap.empty() && mp[heap.top()] > 0) {
                    mp[heap.top()]--;
                    heap.pop();
                }
            }
            cur = heap.top();
            if (cur != pre) {
                ans.push_back({h.first, cur});
                pre = cur;
            }
        }
        return ans;
    }
};
