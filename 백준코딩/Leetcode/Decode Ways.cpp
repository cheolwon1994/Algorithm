class Solution {
public:
    int sum[101];

    int bruteforce(int idx, string s){
        if(sum[idx]!=-1) return sum[idx];
        int answer = 0;
        int len = s.size();
        //end
        if(idx==len){
            sum[idx]=1;
            return 1;
        }
        //check if s[idx]=='0'
        if(s[idx]=='0'){
            sum[idx]=0;
            return 0;
        }
        //last index
        if(idx==len-1){
            sum[idx]=1;
            return 1;
        }

        string ss = s.substr(idx,2);
        //can be 2 ways
        if(ss<="26") answer+=bruteforce(idx+2,s);
        //just 1char
        answer += bruteforce(idx+1,s);
        sum[idx] = answer;
        return answer;
    }

    int numDecodings(string s) {
        int len = s.size();
        for(int i=0;i<=len;i++)
            sum[i] = -1;
        bruteforce(0,s);
        return sum[0];
    }
};
