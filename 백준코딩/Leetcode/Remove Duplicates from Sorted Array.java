class Solution {
    public int removeDuplicates(int[] nums) {
        int cnt=0;
        int dupNum = -101;
        for(int i=0;i<nums.length;i++){
            int val = nums[i];
            if(val!=dupNum){
                dupNum=val;
                nums[cnt++]=val;
            }
        }
        return cnt;
    }
}
