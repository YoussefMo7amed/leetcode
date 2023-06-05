class Solution {
public:
    int delta(int a, int b){
        return b - a;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates){
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        int deltaX = delta(x1, x2);
        int deltaY = delta(y1, y2);

        for (int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if (deltaY * delta(x1, x) != delta(y1, y) * deltaX)
                return false;
        }
        return true;
    }
};