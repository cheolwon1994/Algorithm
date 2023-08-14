class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum  = 0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        double answer = sum/k;

        int l = 0, r = k-1, len = nums.size();
        while(r < len){
            if(r+1 < len){
                sum -= nums[l++];
                sum += nums[++r];
                answer = max(answer, sum/k);
            }
            else break;
        }

        return answer;
    }
};
