class Solution {
public:
    bool finish = false;

    void nextPermutation(vector<int>& nums) {
        //1. find the first i where nums[i] < nums[i+1] from right
        vector<int> v;
        int len = nums.size();
        int idx = -1;
        for(int i = len-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        //2-1. if idx == -1, get first permutation of nums
        if(idx==-1){
            sort(nums.begin(),nums.end());
        }
        //2-2. if idx exists, get index j starting from the right where nums[idx] < nums[j]
        else{
            int j;
            for(int i=len-1;i>idx;i--){
                if(nums[idx] < nums[i]){
                    j = i;
                    break;
                }
            }
            //3. swap nums[idx] and nums[j]
            int temp = nums[idx];
            nums[idx] = nums[j];
            nums[j] = temp;

            //4. reverse nums[idx+1] ~ nums[len-1]
            std::reverse(nums.begin()+idx+1, nums.end());
        }
    }
};
