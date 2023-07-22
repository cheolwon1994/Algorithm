class Solution {
public:

    int binarySearch(vector<int> nums, int target, bool findBigger){
        int l = 0;
        int r = nums.size()-1;
        int answer = -1;
        bool found = false;
        while(l>=0 && l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target) found = true;
                answer = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        if(findBigger) return answer;
        return found ? answer : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        int startIdx = binarySearch(nums,target,false);
        if(startIdx==-1){
            answer.push_back(-1);
            answer.push_back(-1);
        }
        else{
            answer.push_back(startIdx);
            int endIdx = binarySearch(nums,target+1,true)-1;
            //not found and startIdx = 0 and no bigger value than target
            if(endIdx==-2) endIdx = nums.size()-1;
            answer.push_back(endIdx);
        }
        return answer;
    }
};
