class Solution {
public:
    vector<vector<int>> answer;
    bool flag[8]={false,};
    //create a set to exclude duplicate
    set<vector<int>> s;

    void dfs(vector<int>& v, vector<int>& nums){
        int len = nums.size();
        int vlen = v.size();
        if(len==vlen){
            s.insert(v);
            return;
        }

        for(int i=0;i<len;i++){
            if(!flag[i]){
                flag[i]=true;
                int val = nums[i];
                v.push_back(val);
                dfs(v,nums);
                v.pop_back();
                flag[i]=false;
            }

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //Initialize
        //sort nums and set answer and flag as global values making flag's value as all false
        sort(nums.begin(),nums.end());

        //make dfs function having parameter nums and vector v which includes elements 
        vector<int> v;
        dfs(v, nums);

        //get keys from set
        for(auto it = s.begin();it!=s.end();it++)
            answer.push_back(*it);
        return answer;
    }
};
