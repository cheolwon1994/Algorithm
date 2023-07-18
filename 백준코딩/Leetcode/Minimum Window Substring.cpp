class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0, tlen = t.size(), cnt=0;
        int lidx = -1,ridx;
        map<char,int> window,filled;
        for(int i=0;i<tlen;i++){
            window[t[i]]+=1;
        }
        char c = s[r];
        filled[c]+=1;
        if(window[c]>0) cnt++;
        
        while(l<=r && r<s.size()){
            //compare if all filled
            if(cnt==tlen){
                if(lidx==-1){
                    lidx = l;
                    ridx = r;
                }
                //if answer can be minimum
                else if(ridx-lidx > r-l){
                    lidx = l;
                    ridx = r;
                }
                
                //move l
                if(l==r){
                    if(r==s.size()-1) break;
                    c=s[++r];
                    //if new char satisfies window char, increase count
                    if(window[c]>0 && window[c]>filled[c]) cnt++;
                    //increase filled map
                    filled[c]+=1;
                }
                //decrease filled map
                else{
                    c = s[l];
                    filled[c]-=1;
                    if(window[c]>0 && window[c]>filled[c]) cnt--;
                    c = s[++l];
                }
            }
            //move r
            else{
                if(r==s.size()-1) break;
                c=s[++r];
                //if new char satisfies window char, increase count
                if(window[c]>0 && window[c]>filled[c]) cnt++;
                //increase filled map
                filled[c]+=1;
            }
        }
        return lidx == -1 ? "" : s.substr(lidx,ridx-lidx+1);
    }
};
