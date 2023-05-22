class Solution {
    public int removeDuplicates(int[] nums) {
        int dupNum = -10001;
        int cnt=0, dup=0;
        for(int i=0;i<nums.length;i++){
            int val = nums[i];
            if(val!=dupNum){
                nums[cnt++]=val;
                dup=1;
                dupNum=val;
            }
            else{
                dup++;
                if(dup>2) continue;
                else{
                    nums[cnt++]=val;
                }
            }
        }
        return cnt;
    }
}
