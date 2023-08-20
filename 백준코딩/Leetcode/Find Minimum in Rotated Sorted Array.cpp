class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len-1;
        int answer = 0;

        while(l <= r) {
            int mid = l + (r - l)/2;
            int val = nums[mid];
            if(val <= nums[len-1]){
                answer = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return nums[answer];
    }
};
