#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    int dfs(int i, set<int>& visits)
    {
        if (visits.find(i) != visits.end())
            return 0;
        visits.insert(i);
        for (int e = 0; e < adj[i].size(); e++) {
            dfs(adj[i][e], visits);
        }
        return visits.size();
    }
    int maximumDetonation(vector<vector<int>>& bombs)
    {
        int sz = bombs.size();
        adj = vector<vector<int>>(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if(i == j) continue;
                long long  x1 = bombs[i][0];
                long long  y1 = bombs[i][1];
                long long  r1 = bombs[i][2];

                long long  x2 = bombs[j][0];
                long long  y2 = bombs[j][1];
                long long  r2 = bombs[j][2];

                long long  d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

                if (d <= r1) {
                    adj[i].push_back(j);
                }
                
            }
        }
        int res = 0;
        set<int> s;
        for (int i = 0; i < sz; i++) {
            res = max(res, dfs(i, s));
            s.clear();
        }   
        return res;
    }
};