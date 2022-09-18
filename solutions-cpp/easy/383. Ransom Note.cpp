class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> rn ;

    map<char,int> m;

    for(char c: ransomNote)

      rn[c] = rn[c] + 1;

     for(char c: magazine )

       m[c] = m[c] +1 ;



       for(auto i: rn){

         if(m[i.first] < i.second)

           return false;

       }

       return true;
    }
};
