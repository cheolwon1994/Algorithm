class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        map<int, int> m;

        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(m.find(diff) != m.end()){
                answer.push_back(m[diff]);
                answer.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }

        return answer;
    }
};
