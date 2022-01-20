// class Solution {
// public:
//     int missingNumber(vector<int>& v) {
//         int n = v.size();
//         sort(v.begin(), v.end());
//         // v.push_back(n);
//         for(int i = 0; i<n; i++)
//             if(v[i] != i)
//                 return i;
//         return n;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        for(int i = 0; i<n; i++){
            if((i^v[i]) != 0)
                return i;
        }
        return n;
    }
};
