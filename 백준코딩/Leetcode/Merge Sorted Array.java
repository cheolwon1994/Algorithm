class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
      int lidx = 0;
			int ridx = 0;
			int idx = 0;
			int temp[] = Arrays.copyOf(nums1, m);
			
			while(lidx <m && ridx<n) {
				int lnum = temp[lidx];
				int rnum = nums2[ridx];
				if(lnum<=rnum) {
					nums1[idx++]=lnum;
					lidx++;
				}
				else {
					nums1[idx++]=rnum;
					ridx++;
				}
			}
			
			while(lidx<m) {
				nums1[idx++]=temp[lidx++];
			}
			while(ridx<n) {
				nums1[idx++]=nums2[ridx++];
			}
    }
}
