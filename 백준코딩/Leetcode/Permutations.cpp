class Solution {
public:
    vector<vector<int>> answer;
    bool flag[6]={false,};

    void dfs(vector<int>& v, vector<int>& nums){
        if(v.size()== nums.size()){
            answer.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!flag[i]){
                flag[i]=true;
                v.push_back(nums[i]);
                dfs(v,nums);
                v.pop_back();
                flag[i]=false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        dfs(v, nums);
        return answer;
    }
};
