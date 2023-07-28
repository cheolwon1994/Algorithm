class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        int alphaCnt[26] = {0,};
        int plen = p.size();
        set<char> set;
        for(int i=0;i<plen;i++){
            char c = p[i];
            alphaCnt[c-'a']++;
            set.insert(c);
        }
        int l=0,r=0,slen = s.size();
        while(l<=r && l+plen<=slen){
            char c = s[r];
            //added needed char
            if(--alphaCnt[c-'a']>=0){
                if(r-l+1<plen){
                    if(++r==slen) break;
                    continue;
                }
                answer.push_back(l);
                //end char
                if(++r==slen) break;
                c = s[l++];
                alphaCnt[c-'a']++;
            }
            else{
                //char not in p
                if(set.find(c)==set.end()){
                    for(int i=l;i<=r;i++){
                        c = s[i];
                        alphaCnt[c-'a']++;
                    }
                    if(++r==slen) break;
                    l = r;
                }
                else{
                    while(1){
                        char leftChar = s[l++];
                        alphaCnt[leftChar-'a']++;
                        if(leftChar==c){
                            alphaCnt[leftChar-'a']++;
                            break;
                        }
                    }
                }
            }
        }
        return answer;
    }
};
