class Solution {
   public:
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> morse = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                            "--.",  "....", "..",   ".---", "-.-",  ".-..",
                            "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--",  "-..-",
                            "-.--", "--.."};
        set<string> s;
        for (string word : words) {
            string code;
            for (char c : word) {
                code += morse[c-'a'];
            }
            s.insert(code);
        }
        return s.size();
    }
};
