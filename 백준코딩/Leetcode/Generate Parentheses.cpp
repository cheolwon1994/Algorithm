class Solution {
public:
    vector<string> answer;

    void dfs(int open, int close, string s, int n){
        if(open + close == 2*n){
            answer.push_back(s);
            return;
        }
        if(open==close){
            dfs(open+1,close,s+"(",n);
        }
        else if(open > close){
            if(open<n){
                dfs(open+1,close,s+"(",n);
            }
            dfs(open,close+1,s+")",n);
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(1,0,"(",n);
        return answer;
    }
};
