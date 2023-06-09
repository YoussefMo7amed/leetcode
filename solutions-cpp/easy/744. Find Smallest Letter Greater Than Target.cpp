// brute force 
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        char c = letters[0];
        for (int i = 0; i < size; i++){
            if(letters[i] > target){
                c = letters[i];
                break;
            }
        }
        return c;
    }
};


// binary search 
// Time complexity: O(log(N))
// Space complexity: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        char c = letters[0];
        auto index = upper_bound(letters.begin(), letters.end(), target);
        if(index !=letters.end())
            c = letters[(index- letters.begin())];
        return c;
    }
};
