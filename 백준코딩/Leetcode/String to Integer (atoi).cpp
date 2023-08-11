class Solution {
public:
    int myAtoi(string s) {
        string number ="";
        long long answer = 0;
        bool positive = true;
        int idx = 0, len = s.size();
        //1
        while(idx<len){
            char c = s[idx];
            if(c==' ') idx++;
            else break;
        }
        //2
        if(idx<len){
            if(s[idx]=='-'){
                positive = false;
                idx++;
            }
            else if(s[idx]=='+'){
                idx++;
            }
        }

        //3
        while(idx<len){
            char c = s[idx];
            if('0'<=c && c<='9') {
                idx++;
                if(number=="" && c=='0') continue;
                number+=c;
            }
            else break;
        }
        
        //4
        if(number.size()>0){
            string intMax = "2147483647";
            string intMin = "2147483648";
            if(positive){
                if(number.size()>intMax.size() || (number.size()==intMax.size() && number >= intMax)){
                    answer = INT_MAX;
                }
                else answer = stol(number);
            }
            else{
                if(number.size()>intMin.size() ||  (number.size()==intMin.size() && number >= intMin)){
                    answer = INT_MIN;
                }
                else answer = stol(number)*-1;
            }
        }
        return answer;
    }
};
