class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> triplets;
        set<vector<int>> s;
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            triplets.clear();
            int first = it->first;
            int occurrence = it->second;

            if (occurrence > 1) {
                int third = -(2 * first);
                if (third == first && occurrence == 2) continue;
                if (mp.find(third) != mp.end()) {
                    triplets = {first, first, third};
                    sort(triplets.begin(), triplets.end());
                    s.insert(triplets);
                }
            }
            for (map<int, int>::iterator it2 = next(it, 1); it2 != mp.end();
                 it2++) {
                int second = it2->first;

                // so the sum of them equals zero
                int third = -(first + second);

                // because i know it's sorted and i go from left (small number)
                // to right (big number)
                // e.g. first = -1, second = 3 , third = -2
                // so we counted "-2" before or it doesn't exist.
                if (third <= first || third <= second) continue;

                // i see if this third number exists
                if (mp.find(third) != mp.end()) {
                    // make sure that its not the same number
                    if (third == first || third == second) {
                        if (mp[third] < 2) continue;
                    }

                    // i made it like that so the set can compare and leave the
                    // unique vector because {1,2,3} not same as {3,2,1} etc
                    triplets = {first, second, third};
                    sort(triplets.begin(), triplets.end());
                    s.insert(triplets);
                }
            }
        }
        for (vector<int> t : s) {
            ans.push_back(t);
        }
        return ans;
    }
};
