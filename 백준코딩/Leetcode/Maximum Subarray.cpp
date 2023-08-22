class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        if(len==1) return nums[0];
        
        int mini = 0;
        int answer = nums[0];

        for(int i=0;i<len;i++){
            sum += nums[i];
            answer = max(answer, sum-mini);
            mini = min(mini, sum);
        }
        return answer;
    }
};
