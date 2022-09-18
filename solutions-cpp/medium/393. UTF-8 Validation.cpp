
class Solution {
   public:
    bool validUtf8(vector<int> &data) {
        string binary;
        vector<string> utf;
        int n = data.size();
        for (int i : data) {
            utf.push_back(bitset<8>(i).to_string());
        }
        bool new_char = true;
        int rest = -1;
        for (int i = 0; i < n; i++) {
            if (new_char) {
                if (utf[i][0] != '0') {
                    auto find = utf[i].find('0');
                    if (find != string::npos) {
                        rest = find - 1;
                        if (rest >= 4 || rest < 1) return false;
                        new_char = false;
                    } else
                        return false;
                }
            } else {
                if (rest > 0) {
                    if (!(utf[i][0] == '1' && utf[i][1] == '0')) return false;
                    rest--;
                }
                if (!rest) new_char = true;
            }
        }
        return new_char;
    }
};