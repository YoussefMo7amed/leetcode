class Solution {

public:

   vector<string> commonChars(vector<string>& words) {

		vector<int>occ(26,INT_MAX);

		for(auto w:words){

			vector<int>v(26,0);

			for(auto c:w) v[c-'a']++;

			for(int i=0;i<26;i++) occ[i] = min(occ[i],v[i]);

		}

		vector<string>ans;

		for(int i=0;i<26;i++){

			while(occ[i]--) ans.push_back(string(1,i+'a'));

		}

		return ans;

	}

};