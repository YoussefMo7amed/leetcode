class Solution {
   public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        priority_queue<int> pq;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(pq.size() < k){
                    pq.push(matrix[i][j]);
                } else {
                    if(matrix[i][j] < pq.top()){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};
===============
class Solution {
   public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        map<int, int> mp;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[matrix[i][j]]++;
            }
        }
        int no = 0;
        int ans = -1;
        for (auto i : mp) {
            no += i.second;
            if (no >= k) {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};
