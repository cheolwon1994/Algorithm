class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen = b.size();

        int maxLen = max(alen, blen);
        int idx = 0;
        int carry = 0;
        string answer = "";

        while(idx<maxLen){
            int sum = carry;
            if(idx<alen && a[alen-1-idx]=='1') sum++;
            if(idx<blen && b[blen-1-idx]=='1') sum++;
            carry = sum/2;
            sum%=2;
            if(sum%2==0) answer = "0"+answer;
            else answer = "1"+answer;
            idx++;
        }
        if(carry==1) answer = "1"+answer;
        return answer;
    }
};
