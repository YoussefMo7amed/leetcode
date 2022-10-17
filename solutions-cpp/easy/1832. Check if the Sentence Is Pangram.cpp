class Solution {
   public:
    bool checkIfPangram(string sentence) {
        set<int> s;
        for (char c : sentence) s.insert(c);
        return s.size() == 26;
    }
};