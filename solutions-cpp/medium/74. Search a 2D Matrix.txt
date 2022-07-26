class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;
        for(vector<int> row: matrix){
            flag = binary_search(row.begin(), row.end(), target);
            if(flag)
                return true;
        }
        return false;
    }
};
