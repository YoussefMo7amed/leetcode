#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            adj[manager[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({ headID, 0 });
        int ans = 0;
        while (q.size()) {
            int index = q.front().first;
            int time = q.front().second;
            q.pop();
            ans = max(ans, time);

            for (auto emp : adj[index]) {
                q.push({ emp, time + informTime[index] });
            }
        }
        return ans;
    }
};