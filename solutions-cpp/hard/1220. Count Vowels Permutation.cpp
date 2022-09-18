class Solution {
   public:
    map<char, vector<char>> mp;
    int mod = 1e9 + 7;
    map<pair<char, int>, int> cache;

    long long on(int n, char ch) {
        if (n == 1) {
            return mp[ch].size();
        }
        if(cache.find(make_pair(ch, n)) != cache.end()){
            return cache[make_pair(ch, n)];
        }
        int sum = 0;
        for (char c : mp[ch]) {
            sum += on(n - 1, c);
            if (sum >= mod) {
                sum -= mod;
            }
        }
        return cache[make_pair(ch, n)] = sum;
    }
    int countVowelPermutation(int n) {
        if (n == 1) return 5;
        // each character come from :
        mp['a'] = {'e', 'i', 'u'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'e', 'o'};
        mp['o'] = {'i'};
        mp['u'] = {'i', 'o'};

        long long sum = 0;
        for (auto i : mp) {
            sum += on(n - 1, i.first);
            if (sum >= mod) {
                sum -= mod;
            }
        }
        return (int)sum;
    }
};
