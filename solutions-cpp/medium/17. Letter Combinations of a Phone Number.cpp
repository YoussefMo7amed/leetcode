class Solution {
   public:
    map<int, vector<char>> phone;
    vector<string> ans;
    void init() {
        phone[2] = {'a', 'b', 'c'};
        phone[3] = {'d', 'e', 'f'};
        phone[4] = {'g', 'h', 'i'};
        phone[5] = {'j', 'k', 'l'};
        phone[6] = {'m', 'n', 'o'};
        phone[7] = {'p', 'q', 'r', 's'};
        phone[8] = {'t', 'u', 'v'};
        phone[9] = {'w', 'x', 'y', 'z'};
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        init();
        string current = "";
        backtrack(digits, 0, current);
        return ans;
    }
    void backtrack(string &digits, int index, string &current) {
        if (index == digits.size()) {
            ans.push_back(current);
        } else {
            int digit = digits[index] - '0';
            for (int i = 0; i < phone[digit].size(); i++) {
                current.push_back(phone[digit][i]);
                backtrack(digits, index + 1, current);
                current.pop_back();
            }
        }
    }
};