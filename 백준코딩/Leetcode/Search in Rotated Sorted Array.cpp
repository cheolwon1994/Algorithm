class Solution {
public:
    int bst(int l, int r, int target, vector<int> nums){
        //if the element is bigger thant the biggest or smaller than the smallest, return -1
        int answer = -1;
        if(target < nums[l] || target > nums[r]) return answer;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(target==nums[mid]){
                answer = mid;
                break;
            }
            else if(target<nums[mid]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return answer;
    }

    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int from, to,l=0,r=len-1,answer=0;
        //#1. check nums[0] <= nums[len-1], =for array having only 1 element
        //#1-1. if nums[0] < nums[len-1], no rotation has occured
        if(nums[0]<=nums[r]){
            from = 0;
            to = len-1;
            return bst(from,to,target,nums);
        }
        //#1-2. find the lowest element using binary search
        int tidx,minNum;
        while(l<=r){
            int mid = l + (r-l)/2;
            //can go more left
            if(nums[mid]<=nums[len-1]){
                minNum = nums[mid];
                tidx = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        cout <<"tidx, minNum: "<<tidx<<" "<<minNum<<endl;
        //search from tidx~len-1
        if(target<=nums[len-1]){
            return bst(tidx,len-1,target,nums);
        }
        else{
            return bst(0,tidx-1,target,nums);
        }
    }
};
