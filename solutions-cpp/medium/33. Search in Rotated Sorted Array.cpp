class Solution {
public:
    int search(vector<int>& nums, int target) {
        int indx =  0;
        map<int, int> mp;
        for(int i: nums){
            mp[i] = indx++;
        }
        if(mp.find(target) != mp.end()){
            return mp[target];
        } else {
            return -1;
        }
    }
};
==================
class Solution {
public:
    int search(vector<int> v, int t) {
        if(v.size() == 0)
            return -1;
        if(v.size() == 1)
                return ((v[0] == t)?0:-1);
        int p1 = 0, p2 = v.size() -1 ;
        int idx = -1;
        while(p1 != v.size()-1 && p2 != 0)
        {
            if(v[p1+1] < v[p1])
            {
                idx = p1+1;
                break;
            }
            p1++;
            if(v[p2] < v[p2-1])
            {
                idx = p2;
                break;
            }
            p2--;
        }
        int r, l;
        if(idx!=-1)
        {
            if(t<=v[v.size()-1])
            {
                l = idx;
                r = v.size()-1;
            }
            else
            {
                l = 0;
                r = idx -1 ;
            }
        }
        else
            l = 0, r = v.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(v[m] == t)
                return m;
            else if (v[m] > t)
                r = m - 1 ;
            else
                l = m + 1;
        }
        return -1;
    }
};
