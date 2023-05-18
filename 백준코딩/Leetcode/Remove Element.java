class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int cnt = 0;
        for(int i=0;i<len;i++){
            int arrNum = nums[i];
            if(arrNum==val) cnt++;
            else{
                nums[i-cnt] = arrNum;
            }
        }
        return len - cnt;
    }
}
