class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector <vector<int>> v;
        for(int i = 1; i <= n; i++){
            vector <int> row;
            int cur_row = v.size() + 1 ;
            for(int j = 1; j <= cur_row; j++){
                if(j == 1 || j == cur_row){
                    row.push_back(1);
                } else if (j == 2 || j == cur_row-1){
                    row.push_back(cur_row-1);
                } else {
                    int node;
                    node = v[i-1][j-2] + v[i-1][j-1]; // 1-based
                    row.push_back(node);
                }
            }
            v.push_back(row);
        }
        return v[rowIndex];
    }
};
