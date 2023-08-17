class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int answer = nums.size();

        while(l<=r){
            int mid = l + (r-l)/2;
            int val = nums[mid];
            if(val == target) return mid;
            else if(val < target) l = mid+1;
            else{
                r = mid-1;
                answer = mid;
            }
        }
        return answer;
    }
};
