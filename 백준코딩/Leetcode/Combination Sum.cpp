class Solution {
public:
    vector<int> v;

    void dfs(int idx, vector<int> candidates, int target, int sum, vector<vector<int>> &answer){
        if(sum == target){
            answer.push_back(v);
            return;
        }
        if(idx == candidates.size()) return;
        
        int val = candidates[idx];
        if(sum + val > target) return;
        //add
        v.push_back(val);
        dfs(idx, candidates, target, sum + val, answer);
        v.pop_back();
        //don't add
        dfs(idx+1, candidates, target, sum, answer);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        sort(candidates.begin(), candidates.end());

        dfs(0, candidates, target, 0, answer);
        return answer;
    }
};
