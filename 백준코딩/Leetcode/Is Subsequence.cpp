class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sidx = 0,slen = s.size();
        int tidx = 0, tlen = t.size();

        while(sidx<slen && tidx<tlen){
            if(s[sidx]==t[tidx]){
                sidx++;
                tidx++;
            }
            else tidx++;
        }
        return sidx==slen;
    }
};
