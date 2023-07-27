class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        int len = nums.size();
        int sumArr[20005];
        map<int,int> m;     //sum,cnt
        for(int i=0;i<len;i++) sumArr[i+1] = sumArr[i]+nums[i];
        
        //sum of i~j
        for(int i=1;i<=len;i++){
            int val = sumArr[i];
            if(val==k) answer++;
            answer+=m[val-k];
            m[val]+=1;
        }
        return answer;
    }
};
