#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if('A'<=c && c<='Z') ss+=tolower(c);
            else if('a'<=c && c<='z') ss+=c;
            else if('0'<=c && c<='9') ss+=c;
            else continue;
        }
        int l = 0;
        int r = ss.size()-1;
        bool result = true;
        while(l<r){
            if(ss[l]==ss[r]){
                l++;
                r--;
            }
            else{
                result=false;
                break;
            }
        }
        return result;
    }
};
