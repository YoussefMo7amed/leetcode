// leetcode toturial
class Solution {
   public:
    /*
 If we play a token face up (getting 1 score), we might as well play the one with the smallest
 value. Similarly, if we play a token face down, we might as well play the one
 with the largest value (losing 1 score).
    */
    int bagOfTokensScore(vector<int> &tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1;
        int score = 0, max_score = 0;
        while (low <= high && (power >= tokens[low] || score > 0)) {
            // getting score (losing power) by facing up low tokens
            while (low <= high && power >= tokens[low]) {
                power -= tokens[low++];
                score++;
            }
            max_score = max(max_score, score);
            // losing score (getting power) by face down (buy) high tokens.
            if (low <= high && score > 0) {
                power += tokens[high--];
                score--;
            }
        }
        return max_score;
    }
};