class Solution {
public:
    bool finish;
    bool arrived[301]={false,};

    void dfs(int idx, string target, set<string>& s){
        int len = target.size();
        if(idx==len-1){
            finish=true;
            return;
        }
        int remainTargetLen = len-idx;
        string ss = "";
        for(int i=1;i<=remainTargetLen;i++){
            ss += target[idx+i];
            if(arrived[idx+i]) continue;
            if(s.find(ss)!=s.end()){
                dfs(idx+i,target,s);
                arrived[idx+i]=true;
            }
        }
        return;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //initialize
        set<string> set;
        finish=false;
        for(string ss: wordDict)
            set.insert(ss);
        
        dfs(-1,s,set);
        return finish;
    }
};
