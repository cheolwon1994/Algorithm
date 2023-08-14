class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = nums.size();
        int answer = -1;

        int l = 0, r = 0, deletedIdx = -1;
        while(l <= r && r < len){
            int val = nums[r];
            if(val==0){
                if(deletedIdx == -1) deletedIdx = r;
                else{
                    answer = max(answer, r - l - 1);
                    l = deletedIdx + 1;
                    deletedIdx = r;
                }
            }
            r++;
        }
        answer = max(answer, r - l -1);
        return answer;
    }
};
