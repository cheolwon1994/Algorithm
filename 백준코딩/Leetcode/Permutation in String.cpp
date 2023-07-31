class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int len = s1.size();
        map<char,int> m;
        for(int i=0;i<len;i++){
            char c = s1[i];
            m[c]+=1;
        }
        int l = 0,r=0;
        while(l<=r && r<s2.size() && r-l<len){
            char c = s2[r];
            if(m[c]){
                m[c]-=1;
                r++;
            }
            else{
                while(l<r){
                    if(s2[l]==c) break;
                    else m[s2[l++]]+=1;
                }
                if(m[c]) m[c]-=1;
                else l++;
                r++;
            }
        }
        return r-l==len;
    }
};
