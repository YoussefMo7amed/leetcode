class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, en = nums.size()-1;
        while(st <= en){
            int mid = (st+en)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target){
                st = mid+1;
            } else {
                en = mid-1;
            }
        }
        return -1;
    }
};
============
class Solution {
public:
    int search(vector<int> a, int t) {
        int l = 0;
        int r = a.size() -1 ;
        while(l <= r)
        {
            int m = l + r;
            if(a[m] == t)
                return m;
            else if (a[m] > t)
                r = m - 1;
            else
                l = m + 1;
        }
           return -1;
    }
};

