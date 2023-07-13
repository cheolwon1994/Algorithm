class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> v;
        for(int i=0;i<len-2;i++){
            int l = i+1;
            int r = len-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0){
                    s.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum<0) l++;
                else r--;
            }
        }
        for(auto it = s.begin();it!=s.end();it++)
            v.push_back(*it);
        return v;
    }
};
