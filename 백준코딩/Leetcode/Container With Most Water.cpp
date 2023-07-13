class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0;
        int r = len-1;
        int sum = 0;

        while(l<r){
            int minHeight = min(height[l],height[r]);
            sum = max(sum, minHeight*(r-l));
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return sum;
    }
};
