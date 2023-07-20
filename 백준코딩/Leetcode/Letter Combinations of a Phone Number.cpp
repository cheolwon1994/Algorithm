class Solution {
public:
    map<char,string> m;

    void makeMap(){
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
    }
    vector<string> answer;

    void dfs(string digits, string s){
        int len = digits.size();
        int idx = s.size();
        if(len==idx){
            if(len==0) return;
            answer.push_back(s);
            return;
        }
        char c = digits[idx];
        string ss = m[c];
        for(int i=0;i<ss.size();i++){
            dfs(digits,s+ss[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        makeMap();
        dfs(digits,"");
        return answer;
    }
};
