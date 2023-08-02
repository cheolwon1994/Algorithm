class Solution {
public:
    bool check(string s, int l, int r, int removed){
        if(l>=r) return true;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                if(removed) return false;
                return check(s,l+1,r,removed+1) | check(s,l,r-1,removed+1);
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        return check(s,0,s.size()-1,0);
    }
};
