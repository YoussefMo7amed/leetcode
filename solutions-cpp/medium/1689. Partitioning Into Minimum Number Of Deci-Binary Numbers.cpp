/*
 * we can add and remove (1) and (0) as many as we want
 * e.g.
 * 2 => 2-1 => 1 - 1 => 0 ... -1 twice
 * 4 => 4-1 => 3-1 => 2-1 => 1-1 .. (-1) 4 times
 * 13 => 13-10 => 3-1 => 2-1 => 1-1 .. (-10) once, and (-1) 3 times total = 4
 *  instead we could do it as
 *  13 => 13-11 => 2-1 => 1-1 .. total = 3 (largest digit)
 * same with large numbers, then we take the largest digit.
*/
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char x : n){
            ans = max(ans, x-'0');
        }
        return ans;
    }
};
