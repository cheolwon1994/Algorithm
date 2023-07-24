class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int zeros = 0,cnt=0;
        for(int i=0;i<len;i++){
            if(nums[i]==0) zeros++;
        }
        for(int i=0;i<len;i++){
            int val = nums[i];
            if(val==0) cnt++;
            else nums[i-cnt] = val;
        }
        for(int i=len-zeros;i<len;i++)
            nums[i]=0;
    }
};
