class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (r>l){
            int mid = (l+r)/2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (nums[l]==target) return l;
        return -1;
    }
};