class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int val : nums) sum += val;
        int lsum = 0, rsum = sum;

        for(int i=0;i<len;i++){
            int val = nums[i];
            rsum -= val;
            if(lsum == rsum) return i;
            else lsum += val;
        }

        return -1;
    }
};
