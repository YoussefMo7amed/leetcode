class Solution {
public:
    int minFlips(int a, int b, int c)
    {
        const int bits = 32;

        string a_str = std::bitset<bits>(a).to_string();
        string b_str = std::bitset<bits>(b).to_string();
        string c_str = std::bitset<bits>(c).to_string();

        int digits = log2(max({a,b,c})) + 1;

        int steps = 0;
        for (int i = bits - digits; i < bits; i++) {
            if (c_str[i] == '0') {
                if (a_str[i] == '1'){
                    steps++;
                }
                if (b_str[i] == '1'){
                    steps++;
                }
            } else {
                if (a_str[i] == '0' && b_str[i] == '0')
                    steps++;
            }
        }
        return steps;
    }
};