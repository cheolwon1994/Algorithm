class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        int[] dup = new int[len];
        
        for(int i=0;i<len;i++){
            int mod = (i+k)%len;
            dup[mod]=nums[i];
        }
        for(int i=0;i<len;i++) nums[i]=dup[i];
    }
}
