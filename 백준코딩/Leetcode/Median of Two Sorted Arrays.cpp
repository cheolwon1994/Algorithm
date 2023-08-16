class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int alen = nums1.size();
        int blen = nums2.size();
        int sumLen = alen + blen;
        double answer = 0;
        int added = 0;
        int aidx = 0, bidx = 0, cnt = -1;

        while(aidx < alen && bidx < blen){
            int aval = nums1[aidx];
            int bval = nums2[bidx];
            int smaller;
            if(aval <= bval){
                smaller = aval;
                aidx++;
            }
            else{
                smaller = bval;
                bidx++;
            }
            ++cnt;
            if(sumLen % 2 == 0){
                if(cnt == sumLen/2 || cnt == (sumLen/2)-1){
                    answer += (double)smaller;
                    added++;
                }
                if(cnt == sumLen/2) break;
            }
            else{
                if(cnt == sumLen/2){
                    answer = (double)smaller;
                    added++;
                }
            }
        }
        
        //one side has finished
        while(cnt < sumLen/2){
            int val;
            if(aidx == alen) val = nums2[bidx++];
            else val = nums1[aidx++];
            ++cnt;
            if(sumLen % 2 == 0){
                if(cnt == sumLen/2 || cnt == (sumLen/2)-1){
                    answer += (double)val;
                    added++;
                }
                if(cnt == sumLen/2) break;
            }
            else{
                if(cnt == sumLen/2){
                    answer = (double)val;
                    added++;
                }
            }
        }
        return answer/(2-(sumLen%2));
    }
};
