class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int l=0,r=0;
        vector<int> answer;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(l<nums1.size() && r<nums2.size()){
            int lnum = nums1[l];
            int rnum = nums2[r];
            if(lnum == rnum){
                answer.push_back(lnum);
                l++;
                r++;
            }
            else if(lnum > rnum) r++;
            else l++;
        }
        return answer;
    }
};
