class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int l = 0, r=0;
        long long sum = nums[0];
        int answer = len+1;
        while(l<=r && r<len){
            if(sum>=target){
                answer = min(answer, r-l+1);
                if(l==r){
                    r++;
                    if(r==len) break;
                    sum+=nums[r];
                }
                else{
                    sum-=nums[l++];
                }
            }
            else{
                if(r==len-1) break;
                sum+=nums[++r];
            }
        }
        return answer == len+1 ? 0 : answer;
    }
};
