class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = 0;
        queue<int> q; //has index which nums value is 0

        int l = 0, r = 0, len = nums.size();
        while(l <= r && r < len){
            int val = nums[r];
            if(val==0){
                if(k>0){
                    q.push(r);
                    k--;
                }
                //need to remove one flipped 0
                else{
                    answer = max(answer, r - l);
                    if(!q.empty()){
                        l = q.front() + 1;
                        q.pop();
                        q.push(r);
                    }
                    else{
                        l = r+1;
                    }
                }
            }
            r++;
        }
        answer = max(answer, r - l);
        return answer;
    }
};
