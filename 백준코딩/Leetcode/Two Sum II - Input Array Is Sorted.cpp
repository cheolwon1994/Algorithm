class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int len = numbers.size();
        int l = 0;
        int r = len-1;

        while(l<r){
            int sum = numbers[l] + numbers[r];
            if(sum<target) l++;
            else if(sum==target) break;
            else r--;
        }

        answer.push_back(l+1);
        answer.push_back(r+1);
        return answer;
    }
};
