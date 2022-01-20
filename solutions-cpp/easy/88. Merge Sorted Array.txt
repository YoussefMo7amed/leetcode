// class Solution {
// public:
//     void merge(vector<int>& a, int m, vector<int>& b, int n) {
//         if(n == 0)
//             return;
//         for(int i = 0; i < n; i++){
//             a[m+i] = b[i];
//         }
//         sort(a.begin(), a.end());
//     }
// };

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m-1;
        int j =n-1;
        int last = n+m-1;
        while (j >=0){
            if (i>=0 && a[i] > b[j]){
                a[last--] = a[i--];
            }else{
                a[last--] = b[j--];
            }
        }
    }
};
