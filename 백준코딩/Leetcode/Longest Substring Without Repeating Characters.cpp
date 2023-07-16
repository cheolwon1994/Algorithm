class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;       //해당 문자가, 있던 곳
        int len = s.size();
        int answer=0;
        int l=0,r=0;

        while(l<=r && r<len){
            char c = s[r];
            if(m.find(c)==m.end() || m[c]==-1){
                m[c]=r++;
            }
            else{
                int idx = m[c];
                for(int i=l;i<=idx;i++)
                    m[s[i]]=-1;
                m[c] = r;
                l = idx+1;
                r++;
            }
            answer = max(answer, r-l);
        }
        return answer;
    }
};
