class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1,zeroNum=0,mulExceptZero=1;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            mul *= val;
            if(val==0) zeroNum++;
            else mulExceptZero *= val;
        }
        vector<int> answer;
        for(int num: nums){
            int initNum = 0;
            if(zeroNum==1 && num==0) initNum = mulExceptZero;
            else if(zeroNum==0) initNum = mul/num;
            answer.push_back(initNum);
        }

        return answer;
    }
};
