// class Solution {
// public:
//     void moveZeroes(vector<int>& a) {
//         int n = a.size();
//         int i = 0;
//         for(int i = 0; i < n; i++){
//             if(a[i] == 0){
//                 for(int j = i + 1; j < n; j++){
//                     if(a[j] != 0){
//                         swap(a[i], a[j]);
//                         break;
//                     }
//                 }
//             }
//         }

//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(a[i]!= 0){
                a[j++] = a[i];
            }
        }
        while(j < n){
            a[j++] = 0;
        }
    }
};
