class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<string,vector<int>> m;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        for(auto it = m.begin();it!=m.end();it++){
            vector<int> idx = it->second;
            vector<string> v;
            for(int j=0;j<idx.size();j++){
                v.push_back(strs[idx[j]]);
            }
            answer.push_back(v);
        }
        return answer;
    }
};
