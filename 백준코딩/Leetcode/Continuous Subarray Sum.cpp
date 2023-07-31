class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        map<int,int> m;     //save sum[],index
        for(int i=0;i<len;i++){
            sum = (sum+nums[i])%k;
            //length at least two and sum is 0
            if(i>0 && sum==0) return true;
            //already have same remain
            if(m.find(sum)!=m.end()){
                int previous = m[sum];
                //check if length is at least 2
                if(i-previous>=2) return true;
                continue;
            }
            m[sum]=i;
        }
        return false;
    }
};
