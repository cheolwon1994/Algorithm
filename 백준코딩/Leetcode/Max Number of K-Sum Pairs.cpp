class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = 0;
        int l = 0, r = nums.size()-1;

        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum == k){
                answer++;
                l++;
                r--;
            }
            else if(sum < k) l++;
            else r--;
        }

        return answer;
    }
};
