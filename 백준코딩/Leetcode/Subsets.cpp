class Solution {
public:
    vector<vector<int>> answer;
    bool flag[10]={false,};

    void dfs(int idx, int maxCnt, vector<int> v, vector<int> nums){
        int vlen = v.size();
        if(idx==nums.size() && vlen==maxCnt){
            answer.push_back(v);
            return;
        }
        //don't add
        if(vlen==maxCnt){
            dfs(idx+1,maxCnt,v,nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            //add
            if(!flag[i]){
                flag[i]=true;
                v.push_back(nums[i]);
                dfs(i+1,maxCnt,v,nums);
                v.pop_back();
                flag[i]=false;
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        //init
        answer.clear();
        vector<int> v;
        for(int i=0;i<=nums.size();i++){
            dfs(0,i,v,nums);
        }
        return answer;
    }
};
